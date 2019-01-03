# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 15:51:41 by bfalmer-          #+#    #+#              #
#    Updated: 2018/12/26 15:51:42 by bfalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = fillit
FLAGS = -Wall -Wextra -Werror
SRCS = main.c ft_rdch.c free_result.c get_result.c ft_check.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L. libft.a -lft -o $(TARGET)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f *.o

fclean: 
	make clean
	/bin/rm -f $(TARGET)

re: 
	make fclean
	make
