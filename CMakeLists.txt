cmake_minimum_required(VERSION 3.15)
project(basicsource)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    basicsource/main.cpp
    basicsource/prefix.h
    # Add other .cpp/.h files here
)

# Find GLEW
find_package(GLEW REQUIRED)

# Find OpenGL (Windows)
find_package(OpenGL REQUIRED)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIRS})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLEW_LIBRARIES} OpenGL::GL)
