# Set project name and C++ standard
set(PROJECT_NAME alistar_list)
project(${PROJECT_NAME})

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add the alistar_node library as a dependency
if (EXISTS "${CMAKE_SOURCE_DIR}/../node/CMakeLists.txt")
    add_subdirectory("${CMAKE_SOURCE_DIR}/../node" "${CMAKE_BINARY_DIR}/node_build")
endif()

# Add the library as INTERFACE for linking with other projects
add_library(${PROJECT_NAME} INTERFACE)

# Specify include directories for the library
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_SOURCE_DIR}/../node/inc)

# Add an executable for running tests with .out extension
add_executable(test_list.out test/test_list.cpp)

# Link both alistar_list and alistar_node to the test executable
target_link_libraries(test_list.out PUBLIC ${PROJECT_NAME} alistar_node)

