# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 16:56:45 by skapteli          #+#    #+#              #
#    Updated: 2017/11/22 17:11:29 by skapteli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = asm
LIBFT	 = lib/libft/libft.a
LIB_PATH = lib/libft
SRC_PATH = ./src
OBJ_PATH = ./obj
HEADER	 = asm.h
FLS 	 = -O2 -Wall -Wextra -Werror
RAW_SRC	 := $(shell find $(SRC_PATH) -type f | grep -E "\.c$$")
RAW_DIRS := $(shell find $(SRC_PATH) -type d -mindepth 1)
SRCDIRS  = $(RAW_DIRS:./src/%=%)
SRC		 = $(RAW_SRC:./src/%=%)
OBJ 	 = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))
VPATH	 = include:lib:src

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(addprefix $(OBJ_PATH)/,$(SRCDIRS))

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLS) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIB_PATH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c $(HEADER)
	gcc $(FLS) -I ./include -o $@ -c $<

clean:
	@make -C $(LIB_PATH) clean
	@echo "cleaned" libft
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@echo "fcleaned" $(LIBFT)
	@/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
