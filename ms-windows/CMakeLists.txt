# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Last modified: 2021-08-13

cmake_minimum_required(VERSION 3.12)

project(MULTIPLATFORM VERSION 3
        DESCRIPTION "Test external library on MS Windows platform"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")

set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}/external_dll")
add_subdirectory(external_dll)

add_executable(main src/main.cpp)
target_link_libraries(main hello)
