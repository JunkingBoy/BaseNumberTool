cmake_minimum_required(VERSION 3.26)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        main
    PREFIX         ${CMAKE_BINARY_DIR}googletest
    INSTALL_DIR    ${CMAKE_BINARY_DIR}/gtest
    CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DBUILD_GMOCK=OFF
)

FetchContent_GetProperties(googletest)
if(NOT google_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif(NOT google_POPULATED)

# add goole test dependencies
add_dependencies(testTool googletest)

# add google test to include
include_directories(${CMAKE_BINARY_DIR}/gtest/include)

# add test
add_executable(testnumber headfile/number.hpp test/testnumber.cpp)

# add ctest
add_test(NAME TestNumber COMMAND testnumber)