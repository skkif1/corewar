NAME = corewar

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
INC_PATH = ./includes/ ./libft/includes/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = ui.c vm.c process.c environment.c cycle.c operation.c operation_exec.c coding_byte_parser.c util.c utility.c arg_parser.c c_live.c  c_ld.c c_sti.c c_st.c c_add.c c_and.c c_zjmp.c c_ldi.c c_aff.c c_fork.c c_lfork.c c_lld.c c_lldi.c read_write_mem.c ui_util.c ui_helper.c vm_util.c
LIBFT = libftprintf.a
LIB_NAME = -lftprintf -lcurses

FLAG = -Wall -Wextra -Werror
CC = gcc -Ofast

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIB) $(LIB_NAME) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) -o $@ -c $<

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C ./libft/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean all

.PHONY: lib clean fclean re
