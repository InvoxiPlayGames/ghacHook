#include <Shlwapi.h>
#include <string.h>
#include <stdio.h>
#include "config.h"
#include "ini.h"

ghacHook_config config;

#define GHAC_CONFIG_BOOL(x) ((strcmp(x, "true") == 0 || strcmp(x, "TRUE") == 0 || strcmp(x, "True") == 0 || strcmp(x, "1") == 0) ? 1 : 0)

static int handle_config_entry(void* user, const char* section, const char* name, const char* value)
{
	printf("[%s] %s = %s\n", section, name, value);
	if (strcmp(section, "Devices") == 0)
	{
		if (strcmp(name, "EnableIOHooks") == 0)
			config.EnableIOHooks = GHAC_CONFIG_BOOL(value);
		if (strcmp(name, "EnableDongleHooks") == 0)
			config.EnableDongleHooks = GHAC_CONFIG_BOOL(value);
		if (strcmp(name, "EnableDeviceNameHook") == 0)
			config.EnableDeviceNameHook = GHAC_CONFIG_BOOL(value);
	}
	else if (strcmp(section, "Filesystem") == 0)
	{
		if (strcmp(name, "EnableMultiInstallHook") == 0)
			config.EnableMultiInstallHook = GHAC_CONFIG_BOOL(value);
		if (strcmp(name, "SkipCRCChecks") == 0)
			config.SkipCRCChecks = GHAC_CONFIG_BOOL(value);
	}
	else if (strcmp(section, "IO") == 0)
	{
		if (strcmp(name, "DipSwitch") == 0)
		{
			// expecting a value of 8 binary characters
			int i = 0;
			if (strlen(value) == 8)
				for (i = 0; i < 8; i++)
					if (value[i] == '1')
						config.DipSwitch |= (1 << i);
					else
						config.DipSwitch &= ~(1 << i);
		}
	}
	return 1;
}

static void default_config()
{
	memset(&config, 0, sizeof(ghacHook_config));

	// config defaults
	// TODO(Emma): detect if the hooks should be enabled/disabled by default based on system state
    config.EnableIOHooks = 1;
    config.EnableDongleHooks = 1;
    config.EnableDeviceNameHook = 0;
	config.EnableMultiInstallHook = 0;

	config.DipSwitch = 0x60;
}

void load_config()
{
	default_config();
	// parse the INI file
	if (ini_parse("ghacHook.ini", handle_config_entry, NULL) < 0)
	{
		printf("ERROR! FAILED TO LOAD CONFIG! Defaults are being used!\n");
		default_config();
		//ghacHook_fatal("Failed to load config file!");
	}
}
