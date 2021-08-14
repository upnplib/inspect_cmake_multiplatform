# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Redistribution only with this Copyright remark. Last modified: 2021-08-14

cmake_minimum_required(VERSION 3.18)

project(MULTIPLATFORM VERSION 1
        DESCRIPTION "Test external library on multiplatform"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")

include_directories(${PROJECT_SOURCE_DIR}/external_lib/include)


# Using prefered find_library to be platform independent
#-------------------------------------------------------
message("CMAKE_FIND_LIBRARY_PREFIXES is: ${CMAKE_FIND_LIBRARY_PREFIXES}")
message("CMAKE_FIND_LIBRARY_SUFFIXES is: ${CMAKE_FIND_LIBRARY_SUFFIXES}")

find_library(MULTIPLATFORM_SHARED_LIBRARY hello
             PATHS ${PROJECT_SOURCE_DIR}/external_lib/build
             NO_DEFAULT_PATH)
message("MULTIPLATFORM_SHARED_LIBRARY is: ${MULTIPLATFORM_SHARED_LIBRARY}")

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(main ${MULTIPLATFORM_SHARED_LIBRARY})
