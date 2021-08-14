# cmake_multiplatform
Testing cmake to build a library with linking another external library on multiple platforms Linux, MS Windows, macOS and others.

This is mainly a simple test project for my own to learn how cmake commonly builds on different platforms. Here I found some very useful articles:
 - [Creating and using shared libraries with dfferent compilers on different operating systems](https://gernotklingler.com/blog/creating-using-shared-libraries-different-compilers-different-operating-systems/)
 - [CMake link shared library on Windows](https://stackoverflow.com/a/33297026/5014688)
 - [Don't know how to load and use dll file in C](https://stackoverflow.com/a/38337298/5014688)
 - [Importing and Exporting public symbols](https://docs.microsoft.com/en-us/cpp/build/importing-and-exporting?view=msvc-160)

## On Linux
I first create the external library using bash:

    ~$ cd linux/  # This is the project source directory
    linux$ cmake -S external_lib/ -B external_lib/build/
    linux$ cmake --build external_lib/build/

I find the shared library at `linux/external_lib/build/`. Now build the main program

    linux$ cmake -S . -B build
    linux$ cmake --build build

We find the shared main program at `build/`.

    linux$ ./build/main
    Hello World from external library :-)

## On MS Windows
With the Microsoft Visual C Compiler (MSVC) external symbols are not exported by default. We explicitly have to do it with program decorators `__declspec(dllexport)` on symbols in the library (.dll) and with `__declspec(dllimport)` on symbols in the main program (.exe), means where the functions from the library are used. I create the external library using the PowerShell:

    PS > cd ms-windows/  # This is the project source directory
    PS ms-windows> cmake -S .\external_lib\ -B .\external_lib\build\
    PS ms-windows> cmake --build .\external_lib\build\ --config Release

I find the shared library (.dll and corresponding .lib) at `.\external_lib\build\Release\`. Now build the main program

    PS ms-windows> cmake -S . -B .\build\
    PS ms-windows> cmake --build .\build\ --config Release

I find the shared main program at `.\build\Release\` and need to copy the .dll to the main program, otherwise the main program will not find its library. In this case the main program will terminate silently. If you do net get the greeting then look for the .dll:

    PS ms-windows> copy .\external_lib\build\Release\hello.dll .\build\Release\
    PS ms-windows> .\build\Release\main.exe
    Hello World from external library :-)

## On Multiplatform build
We have to ensure that both configurations above are running with one cmake setup. The problem is the different behavior with symbol exports of the different compiler. GCC on Linux exports all symbols by default but MSVC on MS Windows does not and need decorators as already described. We solve this with a preprocessor makro as defined in `external_lib/hello.h` and triggered with a target_compile_definitions() in `external_lib/CMakeLists.txt`.

Now we can use the commands as shown above for the respective platform with the same cmake multiplatform setup.
