cmake_minimum_required(VERSION 3.15)
project(mileStone2_23_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

file(GLOB ALL_FILES "*.h" "*.cpp")

add_executable(mileStone2_23_1 ${ALL_FILES})