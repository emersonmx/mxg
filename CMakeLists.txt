# Project settings
cmake_minimum_required(VERSION 2.8.11)
project(mxg)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/config.cmake)

# Options
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/options.cmake)

# Compiler settings
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/compiler.cmake)

# Build settings
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/build.cmake)
