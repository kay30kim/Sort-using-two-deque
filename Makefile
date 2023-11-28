# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 21:13:41 by kyung-ki          #+#    #+#              #
#    Updated: 2023/11/25 17:05:44 by kyung-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address
NAME		=	push_swap

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources
SRCS	=	src/instruction.c src/list.c src/main.c src/utils.c src/quicksort.c src/mergesort.c src/quicksort2.c
OBJS	=	$(SRCS:.c=.o)

#Library
LIBFT		=	./library/libft
LIBPF		=	./library/ft_printf
LIBS		=	$(LIBFT)/libft.a $(LIBPF)/libftprintf.a
HEADERS		=	-I$(LIBFT)/include -I$(LIBPF) -Iinclude

###
all : libft libpf $(NAME)

libft :
	$(MAKE) -C $(LIBFT)

libpf :
	$(MAKE) -C $(LIBPF)

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBPF) clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBPF) fclean

re : fclean all

.PHONY : all libft libpf clean fclean re