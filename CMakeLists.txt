cmake_minimum_required(VERSION 3.15.0)

project(supercline)

SET(SOVERSION 1)
SET(VERSION 1.0.0)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(cotire)

option(BUILD_CORE "Build core" ON)
option(BUILD_CORE_STATIC "Build core static libraries" OFF)
option(BUILD_LOG "Build log" ON)
option(BUILD_LOG_STATIC "Build log static libraries" OFF)
option(BUILD_AUDIO "Build audio" OFF)
option(BUILD_AUDIO_STATIC "Build audio static libraries" OFF)
option(BUILD_AUDIOFMOD "Build audiofmod" OFF)
option(BUILD_AUDIOFMOD_STATIC "Build audiofmod static libraries" OFF)
option(BUILD_PATHFINDER "Build pathfinder" ON)
option(BUILD_PATHFINDER_STATIC "Build pathfinder static libraries" OFF)

if (BUILD_CORE)
    add_subdirectory(core)
endif ()

if (BUILD_LOG)
    add_subdirectory(log)
endif ()

if (BUILD_AUDIO)
    add_subdirectory(audio)
endif ()

if (BUILD_AUDIOFMOD)
    add_subdirectory(audiofmod)
endif ()

if (BUILD_PATHFINDER)
    add_subdirectory(pathfinder)
endif ()
