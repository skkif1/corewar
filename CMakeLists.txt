cmake_minimum_required(VERSION 3.8)
project(corewar)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        includes/op.h
        src/arg_parser.c
        src/c_add.c
        src/c_aff.c
        src/c_and.c
        src/c_fork.c
        src/c_lfork.c
        src/c_ld.c
        src/c_lld.c
        src/c_ldi.c
        src/c_lldi.c
        src/c_live.c
        src/c_st.c
        src/c_sti.c
        src/c_zjmp.c
        src/coding_byte_parser.c
        src/cycle.c
        src/environment.c
        src/operation.c
        src/operation_exec.c
        src/process.c
        src/read_write_mem.c
        src/ui.c
        src/util.c
        src/utility.c
        src/vm.c src/ui_util.c src/ui_helper.c src/vm_util.c)

add_executable(corewar ${SOURCE_FILES})
target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libftprintf.a -lcurses)