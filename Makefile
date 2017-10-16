CC = gcc -Wall -Wextra -Werror


NAME = corewar

COREWAR = ui.c vm.c process.c environment.c cycle.c operation.c operation_exec.c live.c util.c arg_parser.c

OBJECTS = $(subst .c,.o,$(COREWAR))

$(NAME): $(OBJECTS)
	@make -C libft/
	gcc $(OBJECTS) -o $(NAME) libft/libftprintf.a -lcurses


all: $(NAME)

clean:
	@make -C libft/ clean
	rm -rf $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	rm -rf $(NAME) $(OBJECTS)

re: fclean all
