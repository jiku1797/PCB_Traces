# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.10)

project ("PCB_Traces")

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

include_directories(PCB_Traces)
include_directories(unitTests)

# Include sub-projects.
add_subdirectory ("PCB_Traces")
add_subdirectory("unitTests")
add_subdirectory("gui")

# Google test
add_subdirectory ("lib/gtest")