cmake_minimum_required(VERSION 4.1)
project(tetris__in_c C)

set(CMAKE_C_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(tetris__in_c
        file.c)
target_link_libraries(tetris__in_c PRIVATE
        ${CURSES_LIBRARIES}
        ${CURSES_EXTRA_LIBRARIES}
        tinfo
)
