# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "A:/NumberChangeTool/_deps/googletest-src"
  "A:/NumberChangeTool/_deps/googletest-build"
  "A:/NumberChangeTool/_deps/googletest-subbuild/googletest-populate-prefix"
  "A:/NumberChangeTool/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "A:/NumberChangeTool/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "A:/NumberChangeTool/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "A:/NumberChangeTool/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "A:/NumberChangeTool/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "A:/NumberChangeTool/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
