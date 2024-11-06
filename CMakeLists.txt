cmake_minimum_required(VERSION 3.10)
project(alistar)

# Global settings for the project
# c++11 for nullptr c++14 for functional ?
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories with unique binary directories
add_subdirectory(node ${CMAKE_BINARY_DIR}/node_build)
add_subdirectory(test ${CMAKE_BINARY_DIR}/test_build)
add_subdirectory(list ${CMAKE_BINARY_DIR}/list_build)
add_subdirectory(app ${CMAKE_BINARY_DIR}/app_build)
