cmake_minimum_required(VERSION 4.1)
project(assignment3_bm C)

set(CMAKE_C_STANDARD 11)

add_executable(assignment3_bm
        main.c
        quit.c
        display.c
        createLinkedList.c
        editList.c
        editBoard.c
        loadBoard.c
        saveBoard.c
        sample.txt
)
