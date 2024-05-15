# Staple - Counter-Strike 1.6 Model Reset Tool

Staple is a command-line utility for Counter-Strike 1.6 that resets the game models to their original state by copying default model files from a specified directory to the game's model directory.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Before running Staple, ensure that you have a directory containing the default model files you wish to restore.

### Building

To build Staple, use CMake and your preferred build system. For example, if you're using Make, you can build the project with the following commands:

```sh
cd path_to_staple
mkdir build && cd build
cmake ..
make
```

### Example

```sh
C:/Users/Win10/staple/build/staple.exe "C:\Games\Counter Strike Razer\cstrike\models" "C:\Users\Win10\staple\cfg\staple.cfg"
```