#ifndef CONFIG_H
#define CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ghacHook_config
{
    int EnableIOHooks;
    int EnableDongleHooks;
    int EnableDeviceNameHook;
} ghacHook_config;

extern ghacHook_config config;

void load_config();

#ifdef __cplusplus
}
#endif

#endif // CONFIG_H
