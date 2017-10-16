cmake_minimum_required(VERSION 3.8)
project(corewar)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cycle.c
        environment.c
        live.c
        op.h
        operation.c
        operation_exec.c
        process.c
        ui.c
        vm.c util.c)

add_executable(corewar ${SOURCE_FILES})
target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libftprintf.a -lcurses)

