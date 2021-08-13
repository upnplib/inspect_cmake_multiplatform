# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Last modified: 2021-08-13

cmake_minimum_required(VERSION 3.18)

project(EXTERNAL_LIB VERSION 1
        DESCRIPTION "Test external library"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")

add_library(helloStatic STATIC src/hello.cpp)
add_library(helloShared SHARED src/hello.cpp)
