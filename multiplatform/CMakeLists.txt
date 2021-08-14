# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Last modified: 2021-08-14

cmake_minimum_required(VERSION 3.18)

project(MULTIPLATFORM VERSION 2
        DESCRIPTION "Test external library on MS Windows platform"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")


# needed to find the header file
#-------------------------------
include_directories(${PROJECT_SOURCE_DIR}/external_lib/include)


# Using find_library to be platform independent
#----------------------------------------------
# File prefix and suffix is set by cmake to get them correct
# on the current platform.
message("CMAKE_FIND_LIBRARY_PREFIXES is: ${CMAKE_FIND_LIBRARY_PREFIXES}")
message("CMAKE_FIND_LIBRARY_SUFFIXES is: ${CMAKE_FIND_LIBRARY_SUFFIXES}")

# On MS Windows we may find libraries in different subdirectories depending on
# its type, e.g. Debug/ or Release/. So we have to use PATH_SUFFIXES to look
# also there. The first match is used so you have to decide what you prefer and
# reorder PATH_SUFFIXES. In the example below Debug build will be used if
# available.
find_library(MULTIPLATFORM_SHARED_LIBRARY hello
             PATHS ${PROJECT_SOURCE_DIR}/external_lib/build
             PATH_SUFFIXES Debug Release MinSizeRel RelWithDebInfo
             NO_DEFAULT_PATH)
message("MULTIPLATFORM_SHARED_LIBRARY is: ${MULTIPLATFORM_SHARED_LIBRARY}")

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(main ${MULTIPLATFORM_SHARED_LIBRARY})
