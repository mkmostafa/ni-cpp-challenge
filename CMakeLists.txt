cmake_minimum_required(VERSION 2.8)

project(NI LANGUAGES CXX)

include_directories(
	./
	include
)

add_executable(NI 
src/NI.cpp
src/main.cpp)
target_compile_options(NI PRIVATE -std=c++11 -g)
set_target_properties(NI PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../)

