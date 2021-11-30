cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)
project(picture_comparison)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(compare)

add_executable(picture_comparison main.cpp)

add_subdirectory(compare)
target_link_libraries(picture_comparison ${OpenCV_LIBS})
target_link_libraries(picture_comparison histogram_comparison)