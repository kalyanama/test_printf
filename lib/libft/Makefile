NAME := libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := src/
INC_DIR := inc/
OBJ_DIR := obj/

SRC = \
chr/ft_isalnum.c\
chr/ft_isalpha.c\
chr/ft_isascii.c\
chr/ft_isdigit.c\
chr/ft_isprint.c\
chr/ft_tolower.c\
chr/ft_toupper.c\
get_next_line/get_next_line.c\
lst/ft_lstadd.c\
lst/ft_lstdel.c\
lst/ft_lstdelone.c\
lst/ft_lstiter.c\
lst/ft_lstmap.c\
lst/ft_lstnew.c\
mem/ft_bzero.c\
mem/ft_memalloc.c\
mem/ft_memccpy.c\
mem/ft_memchr.c\
mem/ft_memcmp.c\
mem/ft_memcpy.c\
mem/ft_memdel.c\
mem/ft_memmove.c\
mem/ft_memset.c\
other/ft_intlst_print.c\
other/ft_itoa_base.c\
other/ft_itoa.c\
other/ft_numlen.c\
other/ft_strlst_print.c\
print/ft_putchar.c\
print/ft_putchar_fd.c\
print/ft_putendl.c\
print/ft_putendl_fd.c\
print/ft_putnbr.c\
print/ft_putnbr_fd.c\
print/ft_putstr.c\
print/ft_putstr_fd.c\
str/ft_atoi_base.c\
str/ft_atoi.c\
str/ft_count_words.c\
str/ft_strcat.c\
str/ft_strchr.c\
str/ft_strclr.c\
str/ft_strcmp.c\
str/ft_strcpy.c\
str/ft_strdel.c\
str/ft_strdup.c\
str/ft_strequ.c\
str/ft_striter.c\
str/ft_striteri.c\
str/ft_strjoin.c\
str/ft_strlcat.c\
str/ft_strlen.c\
str/ft_strmap.c\
str/ft_strmapi.c\
str/ft_strncat.c\
str/ft_strncmp.c\
str/ft_strncpy.c\
str/ft_strnequ.c\
str/ft_strnew.c\
str/ft_strnstr.c\
str/ft_strrchr.c\
str/ft_strrev.c\
str/ft_strsplit.c\
str/ft_strstr.c\
str/ft_strsub.c\
str/ft_strtrim.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all :
	@ $(MAKE) -j $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ $(AR) rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

$(OBJ_DIR):
	@ mkdir -p $(dir $(OBJ))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) $(CFLAGS) -c $< -o $@ \
	-I $(INC_DIR)

clean:
	@ if [ -e $(OBJ_DIR) ]; \
	then \
		$(RM) -r $(OBJ_DIR); \
		printf "$(NAME) OBJECTS CLEANED\n";\
	fi;

fclean: clean
	@ if [ -e $(NAME) ]; \
	then \
		$(RM) $(NAME); \
		printf "$(NAME) DESTROYED\n"; \
	fi;

re: fclean all

.PHONY: all clean fclean re