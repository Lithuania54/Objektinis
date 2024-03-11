cmake_minimum_required(VERSION 3.28.3)
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe" )
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe" )
project(Objektinis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(deque)
add_subdirectory(lists)
add_subdirectory(vectors)
