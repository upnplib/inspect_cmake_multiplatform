# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Last modified: 2021-08-13

cmake_minimum_required(VERSION 3.18)

project(EXTERNAL_LIB VERSION 2
        DESCRIPTION "Test external library on platform MS Windows"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")

add_library(helloStatic STATIC src/hello.cpp)   # creates *.lib
set_target_properties(helloStatic PROPERTIES OUTPUT_NAME hello)

add_library(helloShared SHARED src/hello.cpp)   # creates *.dll
set_target_properties(helloShared PROPERTIES OUTPUT_NAME hello)
