# Set project name and C++ standard
set(PROJECT_NAME alistar_app)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include alistar_node library as a subdirectory (when building standalone)
if (EXISTS "${CMAKE_SOURCE_DIR}/../node/CMakeLists.txt")
    add_subdirectory("${CMAKE_SOURCE_DIR}/../node" "${CMAKE_BINARY_DIR}/node_build")
endif()

# Add the main application executable with .out extension
add_executable(${PROJECT_NAME}.out src/main.cpp)

# Link the alistar_node library to the alistar_app executable
target_link_libraries(${PROJECT_NAME}.out PUBLIC alistar_node)

# Include directories to make <node.hpp> accessible
target_include_directories(${PROJECT_NAME}.out PUBLIC ${CMAKE_SOURCE_DIR}/../node/inc)

