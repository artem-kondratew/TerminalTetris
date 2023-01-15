cmake_minimum_required(VERSION 3.24)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tetris main.cpp Tetris.cpp Tetris.h Field.cpp Field.h Figures/T_figure.cpp Figures/T_figure.h Matrix.cpp Matrix.h Figure.cpp Figure.h)

set(CMAKE_CXX_FLAGS "-lncurses")
