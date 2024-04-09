# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "A:/NumberChangeTool/build/_deps/googletest-src"
  "A:/NumberChangeTool/build/_deps/googletest-build"
  "A:/NumberChangeTool/build/gtest"
  "A:/NumberChangeTool/buildgoogletest/tmp"
  "A:/NumberChangeTool/buildgoogletest/src/googletest-populate-stamp"
  "A:/NumberChangeTool/buildgoogletest/src"
  "A:/NumberChangeTool/buildgoogletest/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "A:/NumberChangeTool/buildgoogletest/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "A:/NumberChangeTool/buildgoogletest/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
