cmake_minimum_required(VERSION 3.16)
project(beforeQuarantine)

set(CMAKE_CXX_STANDARD 20)

add_executable(beforeQuarantine main.cpp CDATE_body.cpp CDATE.h)