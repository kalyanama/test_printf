NAME := libftprintf.a

CC := gcc
CFLAGS = -Wall -Wextra -Werror -O3

SRC_DIR := src/
INC_DIR := inc/
OBJ_DIR := obj/
LIB_DIR := ./

LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_OBJ := $(LIBFT_DIR)/*.o
LIBFT_INC := $(LIBFT_DIR)
 
IFLAGS := -I $(INC_DIR) -I $(LIBFT_INC) 

SRC := \
ft_printf.c\
manage_number.c\
manage_string.c\
manage_char.c\
parsers.c\
printers.c\
utils.c


OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(OBJ_DIR) $(OBJ)
	@ $(AR) rc $(NAME) $(OBJ) $(LIBFT_OBJ)
	@ ranlib $(NAME)

$(OBJ_DIR):
	@ mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) $(CFLAGS) -c $< -o $@ \
	$(IFLAGS)

$(LIBFT_OBJ):
	@ $(MAKE) -C $(LIBFT_DIR)

clean:
	@ if [ -e $(OBJ_DIR) ]; \
	then \
		$(RM) -r $(OBJ_DIR); \
		printf "$(NAME) OBJECTS CLEANED\n"; \
	fi;
	@ $(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@ if [ -e $(NAME) ]; \
	then \
		$(RM) $(NAME); \
		printf "$(NAME) DESTROYED\n"; \
	fi;
	@ $(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
