cmake_minimum_required(VERSION 3.24)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tetris main.cpp Tetris.cpp Tetris.h Zones.cpp Zones.h Matrix.cpp Matrix.h Figure.cpp Figure.h Engine.cpp Engine.h Engine.cpp Engine.h)

set(CMAKE_CXX_FLAGS "-lncurses")
