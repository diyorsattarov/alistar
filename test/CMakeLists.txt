# Define project name
set(PROJECT_NAME alistar_test)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add the inc directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add an interface library for linking with other projects
add_library(${PROJECT_NAME} INTERFACE)

# Specify include directories for the library
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add an executable for testing the test suite functionality
add_executable(test_test_suite.out test/test_test_suite.cpp)

# Link the test library to the executable
target_link_libraries(test_test_suite.out PUBLIC ${PROJECT_NAME})

