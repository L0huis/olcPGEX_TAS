cmake_minimum_required(VERSION 3.15)

project(empge CXX)

add_executable(example example.cpp olcPixelGameEngine.h olcPEX_TAS.h)

include(cmake/PGE.cmake)
pge_set_emscripten_options(example)
