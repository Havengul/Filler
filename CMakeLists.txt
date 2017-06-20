cmake_minimum_required(VERSION 3.7)
project(filler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        old/backupvalidator.c
        old/invalidator.c
        old/read.c
        old/validator.c
        filler.h
        main.c
        moves.c
        read.c
        shave.c
        test.c utilities.c sectors.c check_wall.c build_walls.c t_left_b_right.c t_right_b_left.c fill_corner.c)

add_executable(filler ${SOURCE_FILES})