cmake_minimum_required (VERSION 2.8.11)
project (any)
set (CMAKE_CXX_STANDARD 17)
add_executable (var_any var_any.cpp)

add_executable (use_variant use_variant.cpp)
