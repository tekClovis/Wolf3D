# Wolf3D

<p align="center">
  <img src="https://raw.githubusercontent.com/tekClovis/tekClovis/main/gif/wolf3d.gif" width="640" alt="Wolf3D" />
</p>

A Wolfenstein 3D–style first-person shooter written in C with the CSFML library. Epitech project.

1940, WWII. An OSS agent captured during an infiltration mission escapes from the dungeons of Wolfenstein castle and fights his way out, alone, to expose what he has seen.

## Features

- Raycasting engine (DDA, fisheye correction, textured walls, floor)
- Sprite-based enemies that move and shoot
- Weapons: knife, pistol, shotgun, minigun (ammo, magazines, reload, animations)
- HUD (health, ammo, current weapon), medkits and ammo pickups
- Menu system: start, pause, settings, sound settings, window mode selection
- Save / load of the current level
- Gamepad support (joystick 0) alongside keyboard
- 2D / 3D view modes

## Requirements

- Linux
- `gcc`, `make`
- CSFML **2.x** (`graphics`, `system`, `audio`, `window`). CSFML 3.0 is not supported (incompatible API)
- `ncurses`

## Installation

### Option 1: CSFML 2.x from your package manager

Works if your distribution still packages CSFML 2.x (check with `apt-cache policy libcsfml-dev`, `dnf info CSFML-devel`, `pacman -Si csfml`, `zypper info csfml-devel`).

| Distribution        | Command |
|---------------------|---------|
| Debian / Ubuntu     | `sudo apt install build-essential libcsfml-dev libncurses-dev` |
| Fedora / RHEL       | `sudo dnf install gcc make CSFML-devel ncurses-devel` |
| Arch / Manjaro      | `sudo pacman -S base-devel csfml ncurses` |
| openSUSE            | `sudo zypper install gcc make csfml-devel ncurses-devel` |

Then go to [Build & run](#build--run).

### Option 2: build SFML 2.6 and CSFML 2.5.1 from source (any distribution)

Use this if your distribution only ships CSFML 3.0 (e.g. Ubuntu 26.04) or no CSFML at all. Nothing is installed system-wide and no root is needed for the build itself.

1. Install the build dependencies:

| Distribution        | Command |
|---------------------|---------|
| Debian / Ubuntu     | `sudo apt install build-essential git cmake libncurses-dev libx11-dev libxrandr-dev libxcursor-dev libxi-dev libudev-dev libfreetype-dev libopenal-dev libvorbis-dev libogg-dev libflac-dev libgl-dev` |
| Fedora / RHEL       | `sudo dnf install gcc gcc-c++ make git cmake ncurses-devel libX11-devel libXrandr-devel libXcursor-devel libXi-devel systemd-devel freetype-devel openal-soft-devel libvorbis-devel libogg-devel flac-devel mesa-libGL-devel` |
| Arch / Manjaro      | `sudo pacman -S base-devel git cmake ncurses libx11 libxrandr libxcursor libxi systemd-libs freetype2 openal libvorbis libogg flac mesa` |
| openSUSE            | `sudo zypper install gcc gcc-c++ make git cmake ncurses-devel libX11-devel libXrandr-devel libXcursor-devel libXi-devel systemd-devel freetype2-devel openal-soft-devel libvorbis-devel libogg-devel flac-devel Mesa-libGL-devel` |

2. Build and install SFML 2.6.1 and CSFML 2.5.1 into `~/.local/csfml2`:

```sh
P=$HOME/.local/csfml2
git clone --depth 1 --branch 2.6.1 https://github.com/SFML/SFML.git
git clone --depth 1 --branch 2.5.1 https://github.com/SFML/CSFML.git

cmake -S SFML -B SFML/build -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=$P -DBUILD_SHARED_LIBS=ON
cmake --build SFML/build -j"$(nproc)" && cmake --install SFML/build

cmake -S CSFML -B CSFML/build -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=$P -DCMAKE_PREFIX_PATH=$P \
      -DCMAKE_POLICY_VERSION_MINIMUM=3.5
cmake --build CSFML/build -j"$(nproc)" && cmake --install CSFML/build
```

3. Point the compiler and the loader at it (needed for `make` **and** every time you run the game, so add it to your shell rc):

```sh
export CPATH=$HOME/.local/csfml2/include
export LIBRARY_PATH=$HOME/.local/csfml2/lib
export LD_LIBRARY_PATH=$HOME/.local/csfml2/lib
```

## Build & run

```sh
git clone <repository-url> wolf3D && cd wolf3D
make          # builds ./wolf3d (and lib/libmy.a)
./wolf3d
```

Other targets: `make clean`, `make fclean`, `make re`, `make debug`.

## Controls

| Action              | Keyboard      | Gamepad          |
|---------------------|---------------|------------------|
| Move                | `Z` `Q` `S` `D` | Left stick     |
| Turn                | `←` / `→`     | Right stick      |
| Shoot               | `Space`       | Button 7         |
| Reload              | `R`           | Square           |
| Previous weapon     | `A`           | L1               |
| Next weapon         | `E`           | R1               |
| Pause menu          | `Esc`         | Triangle         |
| Menu navigation     | `↑` / `↓`, `Enter` | D-pad, cross |
| Skip intro lore     | `Enter`       |                  |

## Maps

Maps are plain text grids with space-separated cells (see [.maps/.format_map](.maps/.format_map)):

| Char | Meaning     |
|------|-------------|
| `1`  | Wall        |
| `0`  | Empty       |
| `P`  | Player spawn |
| `E`  | Enemy       |

```
1 1 1 1 1 1
1 P 0 1 E 1
1 0 1 0 0 1
1 0 0 1 0 1
1 1 1 1 1 1
```

## Project layout

```
.
├── Makefile
├── include/      # headers
├── lib/          # libmy: custom C helper library
├── src/
│   ├── init/     # initialisation (window, game, textures, sound, ...)
│   ├── game/     # game loop, raycasting, HUD, weapons, entities
│   ├── menu/     # menus and settings
│   ├── save/     # save / load
│   ├── free/     # cleanup
│   └── get_controler/  # gamepad input
├── img/          # textures, sprites, HUD, menu assets
├── font/         # fonts
└── sound/        # music and sound effects
```
