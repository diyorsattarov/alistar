# Define project name
set(PROJECT_NAME alistar_node)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add the inc directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add the test library as a dependency (adjust path if needed)
if (EXISTS "${CMAKE_SOURCE_DIR}/../test/CMakeLists.txt")
    add_subdirectory("${CMAKE_SOURCE_DIR}/../test" "${CMAKE_BINARY_DIR}/test_build")
endif()

# Add an interface library for linking with other projects
add_library(${PROJECT_NAME} INTERFACE)

# Specify include directories for the library
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add an executable for running tests with .out extension
add_executable(test_node.out test/test_node.cpp)

# Link the alistar_node and alistar_test libraries to the test executable
target_link_libraries(test_node.out PUBLIC ${PROJECT_NAME} alistar_test)

# Include directories to access test_suite.hpp
target_include_directories(test_node.out PUBLIC ${CMAKE_SOURCE_DIR}/../test/inc)

