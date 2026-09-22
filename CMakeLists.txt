cmake_minimum_required(VERSION 3.20)

project(Project_1)

add_executable(Project_1
    src/main.cpp
    src/maze.cpp
    src/robot.cpp
)

target_include_directories(Project_1 PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)