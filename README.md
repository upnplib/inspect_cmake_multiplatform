# cmake_multiplatform
Testing cmake to build a library with linking another external library on multiple platforms Linux, MS Windows, macOS and others.

This is mainly a simple test project for my own to learn how cmake commonly builds on different platforms. Here I found some very useful article:
 - [Creating and using shared libraries with dfferent compilers on different operating systems](https://gernotklingler.com/blog/creating-using-shared-libraries-different-compilers-different-operating-systems/)
 - [CMake link shared library on Windows](https://stackoverflow.com/a/33297026/5014688)
 - [Don't know how to load and use dll file in C](https://stackoverflow.com/a/38337298/5014688)
 - [Importing and Exporting public symbols](https://docs.microsoft.com/en-us/cpp/build/importing-and-exporting?view=msvc-160)

 To use this project I first create the external library

    # on linux bash:
    ~$ cd linux/external_lib/
    ~$ cmake -S . -B build
    ~$ cmake --build build

I find the shared and static libraries at `linux/external_lib/build/`. Now build the main program

    ~$ cd linux/
    ~$ cmake -S . -B build
    ~$ cmake --build build

You find the shared and static main program at `linux/build/`.
