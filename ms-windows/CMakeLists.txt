# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Last modified: 2021-08-13

cmake_minimum_required(VERSION 3.18)

project(MULTIPLATFORM VERSION 2
        DESCRIPTION "Test external library on MS Windows platform"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")

include_directories(${PROJECT_SOURCE_DIR}/external_lib/include)


# Using prefered find_library to be platform independent
#-------------------------------------------------------
message("CMAKE_FIND_LIBRARY_PREFIXES is: ${CMAKE_FIND_LIBRARY_PREFIXES}")
message("CMAKE_FIND_LIBRARY_SUFFIXES is: ${CMAKE_FIND_LIBRARY_SUFFIXES}")

find_library(MULTIPLATFORM_STATIC_LIBRARY hello
             PATHS ${PROJECT_SOURCE_DIR}/external_lib/build
             PATH_SUFFIXES Debug Release MinSizeRel RelWithDebInfo
             NO_DEFAULT_PATH)
message("MULTIPLATFORM_STATIC_LIBRARY is: ${MULTIPLATFORM_STATIC_LIBRARY}")

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(main ${MULTIPLATFORM_STATIC_LIBRARY})


#find_library(MULTIPLATFORM_SHARED_LIBRARY helloShared
#             PATHS ${PROJECT_SOURCE_DIR}/external_lib/build
#             PATH_SUFFIXES Debug Release MinSizeRel RelWithDebInfo
#             NO_DEFAULT_PATH)
#message("MULTIPLATFORM_SHARED_LIBRARY is: ${MULTIPLATFORM_SHARED_LIBRARY}")
#
#add_executable(mainShared ${PROJECT_SOURCE_DIR}/src/main.cpp)
#target_link_libraries(mainShared ${MULTIPLATFORM_SHARED_LIBRARY})
