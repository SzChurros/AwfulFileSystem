#!/bin/sh

# ---- Config ----
BUILD_DIR="build"

# ---- Clean ----
rm -rf "$BUILD_DIR" || exit 1
echo "Removed old build dir..."

# ---- Setup ----
mkdir -p "$BUILD_DIR"/bin || exit 1
echo "Created build folder structure..."

# ---- Compile ----
g++ -static -c src/formatter/main.cpp \
    -o build/main.o
echo Compiled...

# ---- Link ----
g++ build/main.o -o build/bin/mkfs.szczafs
echo Linked...Done!