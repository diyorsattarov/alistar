# Set project name and C++ standard
set(PROJECT_NAME alistar_list)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include alistar_node library as a subdirectory (when building standalone)
if (EXISTS "${CMAKE_SOURCE_DIR}/../node/CMakeLists.txt")
    add_subdirectory("${CMAKE_SOURCE_DIR}/../node" "${CMAKE_BINARY_DIR}/node_build")
endif()

# Add the test executable with .out extension
add_executable(test_list.out test/test_list.cpp)

# Link the alistar_node library to the test executable
target_link_libraries(test_list.out PUBLIC alistar_node)

# Include directories to make <list.hpp> and <node.hpp> accessible
target_include_directories(test_list.out PUBLIC ${CMAKE_SOURCE_DIR}/inc ${CMAKE_SOURCE_DIR}/../node/inc)

