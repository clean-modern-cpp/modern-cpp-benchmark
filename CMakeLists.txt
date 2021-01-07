cmake_minimum_required(VERSION 3.14)

project(modern-cpp-benchmark LANGUAGES CXX)

include(cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cpmaddpackage(
  NAME
  benchmark
  GITHUB_REPOSITORY
  google/benchmark
  VERSION
  1.5.2
  GIT_SHALLOW
  TRUE
  OPTIONS
  "BENCHMARK_ENABLE_TESTING Off")

add_compile_options(-Wall -Werror -Wextra -pedantic)

add_subdirectory(src)
