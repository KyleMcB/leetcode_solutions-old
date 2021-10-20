cmake_minimum_required(VERSION 3.10)

project("dynamic program practice")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
find_package(Catch2 REQUIRED)

add_library(catchmain catch2main.cpp)

add_executable(fib fibanocci/fib.cpp)
target_link_libraries(fib PUBLIC catchmain)

add_executable(choose choose/choose.cpp)
target_link_libraries(choose PUBLIC catchmain)