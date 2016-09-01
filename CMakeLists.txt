# Project settings
cmake_minimum_required(VERSION 2.8.11)
project(mxg)

set(mxg_VERSION_MAJOR 0)
set(mxg_VERSION_MINOR 0)
set(mxg_VERSION_REVISION 0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

configure_file(
    "src/mxg/Config.hpp.in"
    "${PROJECT_BINARY_DIR}/Config.hpp"
)

option(BUILD_SANDBOX "Build sandbox code" OFF)
option(BUILD_TESTS "Build tests" OFF)

# Compiler settings
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")
endif()

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
endif()
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__NO_INLINE__ -D_USE_MATH_DEFINES")
    set(CMAKE_EXE_LINKER_FLAGS "-Wl,--subsystem,windows")
endif()

# Includes and libraries settings
include(FindPkgConfig)

# Executable settings
include_directories(src
    ${PROJECT_BINARY_DIR}
)

if (BUILD_SANDBOX)
    add_subdirectory(sandbox)
endif()

if (BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(${PROJECT_NAME}
    src/mxg/Application.cpp
    src/mxg/Game.cpp
)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY src/ DESTINATION include)
