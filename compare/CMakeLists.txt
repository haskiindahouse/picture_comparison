cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)
project(compare)

set(SOURCE_LIB HistogramCompare.cpp)

add_library(histogram_comparison STATIC ${SOURCE_LIB})
