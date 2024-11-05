# Define project name
set(PROJECT_NAME alistar_node)
project(${PROJECT_NAME})

# Add the inc directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add an interface library for linking with other projects
add_library(${PROJECT_NAME} INTERFACE)

# Specify include directories for the library
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add an executable for running tests with .out extension
add_executable(test_node.out test/test_node.cpp)

# Link the library to the test executable
target_link_libraries(test_node.out PUBLIC ${PROJECT_NAME})

