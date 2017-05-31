# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awyart <awyart@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 22:10:59 by awyart            #+#    #+#              #
#    Updated: 2017/05/23 10:22:16 by awyart           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fdf
GRAPH = -framework OpenGL -framework AppKit
FLAGS = -Werror -Wall -Wextra
SRC1 = main.c\
		draw.c\
		init.c\
		pt.c\
		img.c\
		proj.c\

SRC2 = ft_memdel.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strnew.c \
	ft_strsub.c \
	get_next_line.c\
	ft_memalloc.c\
	ft_strsplit.c\
	ft_isdigit.c \
	ft_atoi.c \

SRC3 = ev+-.c\
	evcolor.c \
	evexit.c \
	evrot.c \
	evrot2.c \
	evz.c \
	eviso.c \
	evcolor2.c \
	evcolor3.c


SRC =$(SRC1) $(patsubst %,utility/%,$(SRC2)) $(patsubst %,event/%,$(SRC3))

IPATH = includes
VPATH = srcs

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $^ libmlx.a -I $(IPATH) 

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

