set(CMAKE_CXX_STANDARD 11)
message(STATUS "Starting compilation")
cmake_minimum_required (VERSION 2.6)
project (RISC-V-Sim)
include_directories("${PROJECT_BINARY_DIR}")
file(GLOB_RECURSE SRC LIST_DIRECTORIES false src/*.cpp)
file(GLOB_RECURSE HEADERS LIST_DIRECTORIES false src/*.h)

MESSAGE( STATUS "Compiling files " ${SRC})

add_executable(RISC-V-Sim ${SRC} ${HEADERS})



enable_testing()
file(GLOB_RECURSE TASKS1 RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "tests/*/*.bin")
foreach(test ${TASKS1})
		get_filename_component(fname ${test} NAME_WE)
		string(REGEX MATCH "[\\/].*$" testname ${test})
		add_test(NAME ${testname} COMMAND RISC-V-Sim ${test} ${fname}.res CONFIGURATIONS )
		MESSAGE(STATUS "Added test " ${testname} " for file " ${test})
endforeach()
