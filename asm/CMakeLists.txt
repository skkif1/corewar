cmake_minimum_required(VERSION 3.8)
project(Corewar)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc lib/libft/includes include)
set(SOURCE_FILES
        include/asm.h
        include/op.h

        src/free/free_memory.c
        src/free/free_structures.c

        src/memory/structures.c
        src/memory/list_memory.c

        src/validate/handle_main_information.c
        src/validate/lexical_valid_end_extract_data.c
        src/validate/validate_helpers.c
        src/validate/save_options.c
        src/validate/handle_opcode_args.c
        src/validate/handle_label_and_opcode.c
        src/validate/compare_with_default_op.c

        src/read/get_info_from_file.c

        src/main.c
        src/errors.c
        src/list_manipulations.c
        src/options_manipulations.c
        )

add_executable(asm ${SOURCE_FILES})
target_link_libraries(asm ${CMAKE_SOURCE_DIR}/lib/libft/libft.a)