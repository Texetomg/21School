# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 15:51:41 by bfalmer-          #+#    #+#              #
#    Updated: 2019/01/10 19:02:53 by thorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror 
SRCS = main.c ft_rdch.c get_result.c ft_check.c sub_functions.c brute_field.c
OBJS = $(SRCS:.c=.o)
INC = fillit.h

.PHONY: all clean fclean re lib_c

all: $(NAME)

$(NAME): $(OBJS)
	make lib_c
	$(CC) $(FLAGS) $(OBJS) -I $(INC) -L libft/ -lft -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

lib_c:
	make -C libft

clean:
	/bin/rm -f *.o
	make -C libft/ clean

fclean: 
	make clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: 
	make fclean
	make
