cmake_minimum_required(VERSION 3.21)
project(FluxMax)

set(CMAKE_CXX_STANDARD 20)

add_executable(FluxMax main.cpp Graph.cpp Graph.h FordFulkerson.cpp FordFulkerson.h)
