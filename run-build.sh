#!/bin/bash

# Clean CMake build and run script

# Configuration
BUILD_DIR=".build"
CLI_EXECUTABLE="src/CLI"
QUIET_MODE=false

# Function for clean output
status() {
    if ! $QUIET_MODE; then
        echo "==> $*"
    fi
}

# Clean previous build
status "Preparing build environment..."
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

# Create build directory
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR" || exit 1

# Configure with CMake
status "Configuring project..."
cmake .. -DCMAKE_BUILD_TYPE=Release > /dev/null || {
    echo "Configuration failed!"
    exit 1
}

# Build the project
status "Building project..."
if [[ "$OSTYPE" == "darwin"* ]]; then
    CPU_COUNT=$(sysctl -n hw.ncpu)
else
    CPU_COUNT=$(nproc)
fi

cmake --build . --config Release --parallel $CPU_COUNT > /dev/null || {
    echo "Build failed!"
    exit 1
}

# Run the CLI executable
status "Running application..."
if [ -f "$CLI_EXECUTABLE" ]; then
    echo ""
    ./"$CLI_EXECUTABLE"
    echo ""
    status "Build and run completed successfully"
else
    echo "Error: Executable not found at $BUILD_DIR/$CLI_EXECUTABLE" >&2
    echo "Available executables:" >&2
    find . -type f -executable -print >&2
    exit 1

fi
