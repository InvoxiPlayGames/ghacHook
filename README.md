# ghacHook

Hooks to GHArcade to improve its lifespan and usability in 2025 and beyond.

**THIS IS A WORK IN PROGRESS. IT DOES NOT DO MUCH.**

You will still need a valid authentication dongle to launch the game.

Builds with Visual Studio 2010; options are available to build using either the
Visual Studio 2010 toolset requiring the Visual C++ 2010 Runtime installed, or
Visual Studio 2008 toolset with a statically linked runtime for maximum system
compatibility.

Currently only works with GHAC version 1.37 and later.

Uses [minhook v1.3.2](https://github.com/TsudaKageyu/minhook).

## Features

* Launch the game without an I/O board connected
* Use seperate install folder for multiple GHAC/GH3 installs

## Installation

1. Download the [latest release](https://github.com/InvoxiPlayGames/ghacHook/releases/latest).
    * The release package comes with [simpledllloader](https://github.com/aap/simpledllloader).
2. Extract the ZIP to the GHArcade game directory. On a cabinet, this is at
   `C:\GH3\DEPLOY\GH3`. (partition label `RT-C`)
3. Boot the cabinet to start the game or launch GH3.exe.
