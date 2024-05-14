# Set the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.15)

# Define the project and the languages used
project(Staple VERSION 1.0 DESCRIPTION "Staple CS Model Reset Tool" LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/lib)

# Add  executable with all source files
add_executable(staple src/main.cpp lib/cmdparser.cpp lib/modelreset.cpp)

# Depending on your setup, you might need to link libraries like this:
# target_link_libraries(staple PRIVATE stdc++fs)

# Set the output directory for the executable
set_target_properties(staple PROPERTIES
  RUNTIMtheE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)