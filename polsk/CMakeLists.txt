cmake_minimum_required(VERSION 3.24)
project(polsk C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(polsk
        in_p.c
        in_p.h
        save.c
        struct.c
        struct.h
        test.c)
