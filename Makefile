# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgameiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/12 15:32:27 by dgameiro          #+#    #+#              #
#    Updated: 2018/06/27 19:16:41 by dgameiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

SRC_PATH = srcs
SRC_NAME = ft_bzero.s ft_cat.s ft_isalpha.s ft_isascii.s ft_isdigit.s \
ft_isprint.s ft_memcpy.s ft_memset.s ft_puts.s ft_strcat.s ft_strdup.s \
ft_strlen.s ft_tolower.s ft_toupper.s ft_isalnum.s

OBJ_PATH = objs

NAME = libfts.a

NASM = nasm
NFLAGS = -f macho64

OBJ_NAME = $(SRC_NAME:.s=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.s
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(NASM) $(NFLAGS) -o $@ $<

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	@rm -fv $(NAME)

re : fclean all
