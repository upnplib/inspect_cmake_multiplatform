# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Last modified: 2021-08-14

cmake_minimum_required(VERSION 3.18)

project(EXTERNAL_LIB VERSION 2
        DESCRIPTION "Test external library on platform MS Windows"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")

# creates hello.dll and depending hello.lib
add_library(hello SHARED src/hello.cpp)
