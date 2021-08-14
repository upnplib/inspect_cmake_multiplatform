# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Redistribution only with this Copyright remark. Last modified: 2021-08-14

cmake_minimum_required(VERSION 3.18)

project(EXTERNAL_LIB VERSION 1
        DESCRIPTION "Test external library"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")

add_library(hello SHARED src/hello.cpp)
