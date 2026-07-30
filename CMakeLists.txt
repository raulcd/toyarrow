# Copyright 2026 Raúl Cumplido
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.

cmake_minimum_required(VERSION 3.25)

project(ToyArrow)

option(TOYARROW_BUILD_TESTS "Build the tests" ON)

# Default to a debug build if no build type was specified as this is currently a
# project to learn C++ and Arrow.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      Debug
      CACHE STRING "Choose the type of build.")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(ToyArrow)

target_compile_features(ToyArrow PUBLIC cxx_std_23)

target_sources(
  ToyArrow
  PRIVATE cpp/src/toyarrow/buffer.cc
  PUBLIC FILE_SET HEADERS BASE_DIRS cpp/src FILES cpp/src/toyarrow/buffer.h)

if(TOYARROW_BUILD_TESTS)
  # Add GoogleTest
  include(FetchContent)
  include(GoogleTest)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0)

  FetchContent_MakeAvailable(googletest)
  enable_testing()

  add_executable(buffer_test cpp/src/toyarrow/buffer_test.cc)
  target_link_libraries(buffer_test PRIVATE ToyArrow gtest_main)
  gtest_discover_tests(buffer_test)
endif()
