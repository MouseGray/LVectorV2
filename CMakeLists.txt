cmake_minimum_required(VERSION 3.5)

project(LVector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LVector
    main.cpp
    lvector.cpp
    lvector.h
)
