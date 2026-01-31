#!/bin/bash

# Define the source file and output executable
SOURCE="main.cpp"
OUTPUT="VulkanApp"

# Compile using C++17 and link GLFW/Vulkan libraries
# pkg-config automatically finds the correct library paths and flags
g++ -std=c++17 $SOURCE -o $OUTPUT $(pkg-config --cflags --libs glfw3 vulkan)

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running $OUTPUT..."
    echo "----------------------------------------"
    ./$OUTPUT
else
    echo "Compilation failed."
    exit 1
fi
