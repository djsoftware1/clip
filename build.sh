#!/usr/bin/env sh
# https://github.com/djsoftware1/clip
#
# Created by David Joffe
# Created 8 Jan 2026

set -eu
DJNAME="clipx"

# Requires: cmake, a C++17 compiler

BUILD_DIR=${BUILD_DIR:-build}
BUILD_TYPE=${BUILD_TYPE:-Relesase}

echo "==> Building"
echo "    build dir : $BUILD_DIR"
echo "    build type: $BUILD_TYPE"

cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
cmake --build "$BUILD_DIR"

# optionally after building you may want to do this to install in your local bin folder:
#echo install -Dm755 build/$DJNAME ~/.local/bin/
#install -Dm755 build/$DJNAME ~/.local/bin/
