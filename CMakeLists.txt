cmake_minimum_required(VERSION 3.26)
project(NumberChangeTool)

# src add test case
add_executable(testTool src/AllChangeNumberFinal.cpp headfile/number.hpp)

# set test
enable_testing()

# headfile
include_directories(${CMAKE_SOURCE_DIR}/headfile)

# add subdir
add_subdirectory(test)

# link
# target_link_libraries(testTool library)