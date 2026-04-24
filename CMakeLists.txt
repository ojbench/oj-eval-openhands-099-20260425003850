# CMake minimum and project
cmake_minimum_required(VERSION 3.10)
project(problem_099_code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(code main.cpp)
target_compile_options(code PRIVATE -O2 -Wall -Wextra -Wconversion -Wshadow -Wduplicated-cond -Wlogical-op -Wuseless-cast)
