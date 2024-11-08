# Set project name and C++ standard
set(PROJECT_NAME alistar_benchmark)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the inc directory for benchmark headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add the alistar_test library as dependency
if (EXISTS "${CMAKE_SOURCE_DIR}/../test/CMakeLists.txt")
    add_subdirectory("${CMAKE_SOURCE_DIR}/../test" "${CMAKE_BINARY_DIR}/test_build")
endif()

# Add the library as INTERFACE for linking with other projects
add_library(${PROJECT_NAME} INTERFACE)

# Specify include directories for the library
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add an executable for running tests with .out extension
add_executable(test_benchmark.out test/test_benchmark.cpp)

# Link alistar_benchmark and alistar_test to the test executable
target_link_libraries(test_benchmark.out PUBLIC ${PROJECT_NAME} alistar_test)

# Include directories to access test_suite.hpp in test_benchmark.cpp
target_include_directories(test_benchmark.out PUBLIC ${CMAKE_SOURCE_DIR}/../test/inc)
