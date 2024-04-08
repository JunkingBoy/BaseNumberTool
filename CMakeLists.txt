cmake_minimum_required(VERSION 3.26)
project(NumberChangeTool)

# src
add_executable(testTool src/AllChangeNumberFinal.cpp)

# headfile
include_directories(${CMAKE_SOURCE_DIR}/headfile)

# link
# target_link_libraries(testTool library)