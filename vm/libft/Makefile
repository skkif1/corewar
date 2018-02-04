SRC_PATH = ./src/
OBJ_PATH = ./obj/

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

PRINTF_SRC = ft_printf.c get_modif.c num_list.c number.c number_handler.c \
parse.c str_handler.c string.c char_handler.c util.c wide_str.c util_bonus.c

SRCFLS =  ft_append.c     \
          ft_atoi.c  	  \
          ft_bzero.c 	  \
          ft_isalnum.c 	  \
          ft_isalpha.c 	  \
          ft_isascii.c 	  \
          ft_isdigit.c 	  \
          ft_isprint.c 	  \
          ft_itoa.c       \
          ft_lstadd.c     \
          ft_lstadd_end.c \
          ft_lstdel.c     \
          ft_lstdelone.c  \
          ft_lstiter.c    \
          ft_lstmap.c 	  \
          ft_lstnew.c  	  \
          ft_memalloc.c   \
          ft_memccpy.c    \
          ft_memchr.c     \
          ft_memcmp.c     \
          ft_memcpy.c     \
          ft_memdel.c     \
          ft_memmove.c    \
          ft_memset.c     \
          ft_putchar.c    \
          ft_putchar_fd.c \
          ft_putendl.c    \
          ft_putendl_fd.c \
          ft_putnbr.c     \
          ft_putnbr_fd.c  \
          ft_putstr.c     \
          ft_putstr_fd.c  \
          ft_strcat.c     \
          ft_strchr.c     \
          ft_strclr.c     \
          ft_strcmp.c     \
          ft_strcpy.c     \
          ft_strdel.c     \
          ft_strdup.c     \
          ft_strequ.c     \
          ft_striter.c    \
          ft_striteri.c   \
          ft_strjoin.c    \
          ft_strlcat.c    \
          ft_strlen.c     \
          ft_strmap.c     \
          ft_strmapi.c    \
          ft_strncat.c    \
          ft_strncmp.c    \
          ft_strncpy.c    \
          ft_strnequ.c    \
          ft_strnew.c     \
          ft_strnstr.c    \
          ft_strrchr.c    \
          ft_strsplit.c   \
          ft_strstr.c     \
          ft_strsub.c     \
          ft_strtrim.c    \
          ft_tolower.c    \
          ft_toupper.c    \
          ft_renew.c 	  \
          ft_redup.c 	  \
          ft_lstsort.c    \
          get_next_line.c \
          ${PRINTF_SRC}
OBJECTS = $(SRCFLS:.c=.o)


SRC = $(addprefix $(SRC_PATH),$(SRCFLS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJECTS))
INC = $(addprefix -I,$(INC_PATH))

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: init $(NAME)

$(NAME): $(OBJ) 
	ar rc $@ $^
	ranlib $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: init supp clean fclean re

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: supp clean
	rm -f $(NAME)

re:	fclean all
