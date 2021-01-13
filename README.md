## SDLHook
Hooks SwapWindow and PollEvent to draw ImGui over an openGL application + gdb injector
<p align="center">
  <a href="/LICENSE"><img src="https://img.shields.io/badge/License-MIT-green.svg" alt="MIT License"></a>
  <a><img src="https://img.shields.io/badge/OS-Linux-green.svg" alt="Linux"></a>
  <a><img src="https://img.shields.io/badge/State-Finished-green.svg" alt="Finished"></a>
</p>

#

## How to use
```
git clone https://github.com/seksea/SDLHook
cd SDLHook
vim toolbox.sh # use any text editor you wish and change line 2 to include the name of the process you are injecting into
chmod +x toolbox.sh
sudo ./toolbox.sh -u -b -l # unload if currently injected, build and then load, use -h for help
```

### Basic toolbox.sh usage
| Argument          | Description                           |
| ----------------- | ------------------------------------- |
| -u (--unload)     | Unload the lib if loaded              |
| -l (--load)       | Load/inject the lib via gdb           |
| -b (--build)      | Build to the build/ dir               |
| -h (--help)       | Show help                             |

All args are executed in the order they are written in, for example, "-u -b -l" would unload the cheat, build it, and then load it back into the process.

#

## Found a bug/want to add something?
- [Create a pull request](https://github.com/seksea/SDLHook/compare) ([tutorial](https://github.com/yangsu/pull-request-tutorial))
- [Report a bug](https://github.com/seksea/SDLHook/issues/new)

#

## Screenshots/Examples
[!]