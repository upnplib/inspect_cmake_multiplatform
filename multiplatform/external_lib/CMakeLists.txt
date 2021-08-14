# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Last modified: 2021-08-14

cmake_minimum_required(VERSION 3.18)

project(EXTERNAL_LIB VERSION 2
        DESCRIPTION "Test external library on platform MS Windows"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")


# needed to find the header file
include_directories(${PROJECT_SOURCE_DIR}/include)


# creates hello.dll and depending hello.lib
add_library(hello SHARED src/hello.cpp
)
# We have to set SHARED_EXPORTS to invoke the preprocessor makro to export the
# symbols of this library to be available for calling programs.
target_compile_definitions(hello
        PUBLIC $<$<BOOL:${MSVC}>:SHARED_EXPORTS>
)
