cmake_minimum_required (VERSION 2.8.11)
project (any)
set (CMAKE_CXX_STANDARD 17)

add_executable (var_any var_any.cpp)

add_executable (use_variant use_variant.cpp)

add_executable (variant_list variant_list.cpp)

add_executable (variant_lambda variant_lambda.cpp)

add_executable (map_of_variants map_of_variants.cpp)

add_executable (vittorio_romeo vittorio_romeo.cpp variant_aliases.hpp)
