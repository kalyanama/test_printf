# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/03 15:34:15 by mmalanch          #+#    #+#              #
#    Updated: 2017/11/14 15:14:26 by mmalanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
RM = /bin/rm -rf
SDIR = ./
IDIR = .
FUNCT = $(SDIR)*.c
OBJ = $(patsubst $(SDIR)%.c, %.o, $(FUNCT))

FLAGS = -I$(IDIR) -Wall -Wextra -Werror -c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(FUNCT)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
