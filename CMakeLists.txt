cmake_minimum_required(VERSION 3.17)
project(DynamicProgramming C)

set(CMAKE_C_STANDARD 99)

add_executable(Fib fibonucci.c )

add_executable(isThereAwayTogenerateTargetSumFromGivenArray isThereAwayTogenerateTargetSumFromGivenArray.c)

add_executable(GridTraveller gridTraveller.c include/uthash.h)