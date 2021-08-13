# cmake_multiplatform
Testing cmake to build a library with linking another external library on multiple platforms Linux, MS Windows, macOS and others.

This is mainly a simple test project for my own to learn how cmake commonly builds on different platforms. To use it first create the external library

    # on linux bash:
    ~$ cd linux/external_lib/
    ~$ cmake -S . -B build
    ~$ cmake --build build

You find the shared and static libraries at `linux/external_lib/build/`. Now build the main program

    ~$ cd linux/
    ~$ cmake -S . -B build
    ~$ cmake --build build

You find the sharred and static main program at `linux/build/`.
