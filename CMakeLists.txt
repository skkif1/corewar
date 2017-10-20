cmake_minimum_required(VERSION 3.8)
project(corewar)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        includes/op.h
        src/cycle.c
        src/environment.c
        src/live.c
        src/operation.c
        src/operation_exec.c
        src/process.c
        src/ui.c
        src/vm.c
        src/util.c
        src/arg_parser.c src/ld.c src/sti.c src/st.c)

add_executable(corewar ${SOURCE_FILES})
target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libftprintf.a -lcurses)

