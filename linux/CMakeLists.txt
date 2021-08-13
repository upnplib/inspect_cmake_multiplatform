# Copyright (C) 2021 GPL 3 and higher by Ingo Höft, <Ingo@Hoeft-online.de>
# Last modified: 2021-08-13

cmake_minimum_required(VERSION 3.18)

project(MULTIPLATFORM VERSION 1
        DESCRIPTION "Test external library on multiplatform"
        HOMEPAGE_URL "https://github.com/ingo-h/cmake_multiplatform")

include_directories(${PROJECT_SOURCE_DIR}/external_lib/include)


# Using platform specific hard coded library names
#-------------------------------------------------
#add_library(helloStatic STATIC IMPORTED)
#set_target_properties(helloStatic PROPERTIES
#            IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/external_lib/build/libhelloStatic.a
#)
#
#add_library(helloShared SHARED IMPORTED)
#set_target_properties(helloShared PROPERTIES
#            IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/external_lib/build/libhelloShared.so
#)
#
##add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
#add_executable(mainStatic ${PROJECT_SOURCE_DIR}/src/main.cpp)
#add_executable(mainShared ${PROJECT_SOURCE_DIR}/src/main.cpp)
#
##target_link_libraries(main ${PROJECT_SOURCE_DIR}/external_lib/build/libhelloStatic.a)
#target_link_libraries(mainStatic helloStatic)
#target_link_libraries(mainShared helloShared)


# Using prefered find_library to be platform independent
#-------------------------------------------------------
message("CMAKE_FIND_LIBRARY_PREFIXES is: ${CMAKE_FIND_LIBRARY_PREFIXES}")
message("CMAKE_FIND_LIBRARY_SUFFIXES is: ${CMAKE_FIND_LIBRARY_SUFFIXES}")

find_library(MULTIPLATFORM_STATIC_LIBRARY helloStatic
             PATHS ${PROJECT_SOURCE_DIR}/external_lib/build
             PATH_SUFFIXES Debug Release MinSizeRel RelWithDebInfo
             NO_DEFAULT_PATH)
message("MULTIPLATFORM_STATIC_LIBRARY is: ${MULTIPLATFORM_STATIC_LIBRARY}")

add_executable(mainStatic ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(mainStatic ${MULTIPLATFORM_STATIC_LIBRARY})


find_library(MULTIPLATFORM_SHARED_LIBRARY helloShared
             PATHS ${PROJECT_SOURCE_DIR}/external_lib/build
             PATH_SUFFIXES Debug Release MinSizeRel RelWithDebInfo
             NO_DEFAULT_PATH)
message("MULTIPLATFORM_SHARED_LIBRARY is: ${MULTIPLATFORM_SHARED_LIBRARY}")

add_executable(mainShared ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(mainShared ${MULTIPLATFORM_SHARED_LIBRARY})
