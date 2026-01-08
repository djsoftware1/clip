# clip
# Created by David Joffe - 8 Jan 2026

cmake_minimum_required(VERSION 3.10)
project(clip LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(clip src/main.cpp)

# Set the actual output binary name
# Plain "clip" is unfortunately highly clash-y with \windows\system32 (thus difficult to work around even via path) so we set different name here - dj2026-01
set_target_properties(clip PROPERTIES
    OUTPUT_NAME "clipx"
)
