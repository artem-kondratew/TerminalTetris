cmake_minimum_required(VERSION 3.18)
project(TerminalTetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(tetris main.cpp Tetris.cpp Tetris.h Zones.cpp Zones.h Matrix.cpp Matrix.h Figure.cpp Figure.h Engine.cpp Engine.h Engine.cpp Engine.h)
target_link_libraries(tetris ncurses)

