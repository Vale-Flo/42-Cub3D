# Cub3D

A 3D raycasting game engine inspired by Wolfenstein 3D, built as part of the 42 School curriculum.

## 🎮 Overview

Cub3D is a simple 3D game that uses raycasting techniques to render a pseudo-3D environment from a 2D map. The project recreates the basic mechanics of classic first-person games like Wolfenstein 3D.

## 🎥 Demo

[![Watch the video](preview.gif)]

## 🛠️ Features

- **3D Raycasting Engine**: Real-time 3D rendering using raycasting algorithms
- **Textured Walls**: Different textures for each cardinal direction (North, South, East, West)
- **Player Movement**:
  - WASD keys for movement (forward, backward, strafe left/right)
  - Arrow keys for camera rotation
- **Map Parsing**: Custom `.cub` file format for level configuration
- **Collision Detection**: Players cannot walk through walls
- **Configurable Colors**: Custom floor and ceiling colors via RGB values

## 🎯 Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` / `Q` | Exit game |

## 📋 Requirements

- **Operating System**: Linux
- **Graphics Library**: MiniLibX
- **Compiler**: GCC with flags `-Wall -Wextra -Werror`
- **Dependencies**: X11 development libraries

## 🔧 Installation

1. **Clone the repository**:
```bash
git clone [repository-url]
cd Cub3D
```

2. **Install MiniLibX**:
```bash
# Clone MiniLibX from the official repository
git clone https://github.com/42Paris/minilibx-linux.git
```

3. **Compile the project**:
```bash
make
```

**Note**: Make sure the MiniLibX path in the Makefile matches your installation location. Check the `MLX_PATH` variable in the Makefile and adjust if necessary.

## 🚀 Usage

```bash
./cub3D [path_to_map_file.cub]
```

**Example**:
```bash
./cub3D maps/valid/subject.cub
```

## 🗺️ Map Format

The `.cub` files define textures, colors and the map layout:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0    # Floor color (RGB)
C 225,30,0     # Ceiling color (RGB)

1111111111111
1000000000001
1000N00000001
1000000000001
1111111111111
```

**Map symbols**: `1` = Wall, `0` = Empty space, `N/S/E/W` = Player start position

## ✅ Key Features

- **DDA Algorithm**: Efficient raycasting for wall detection
- **Texture Mapping**: Different textures per wall direction
- **Input Validation**: Comprehensive map and file validation
- **Error Handling**: Detailed error messages for debugging

## 🏫 42 School Project

Part of the graphics programming curriculum focusing on:
- Raycasting algorithms
- Mathematical concepts (vectors, trigonometry)
- Memory management
- File parsing and validation
