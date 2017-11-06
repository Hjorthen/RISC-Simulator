
message(STATUS "Starting compilation")
cmake_minimum_required (VERSION 2.6)
project (RISC-V-Sim)
include_directories("${PROJECT_BINARY_DIR}")
file(GLOB_RECURSE SRC LIST_DIRECTORIES false *.cpp)

MESSAGE( STATUS "Compiling files " ${SRC})

add_executable(RISC-V-Sim ${SRC})
