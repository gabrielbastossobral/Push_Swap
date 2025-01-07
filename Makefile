# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 17:04:56 by gabrielsobr       #+#    #+#              #
#    Updated: 2025/01/07 17:12:25 by gabrielsobr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	src/main.c \
        src/sort_3.c \
        src/sort_4.c \
        src/sort_5.c \
        src/index.c \
        src/utils.c

OBJS =	main.o \
        sort_3.o \
        sort_4.o \
        sort_5.o \
        index.o \
        utils.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
    @$(MAKE) -C ./libft
    @$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

main.o: src/main.c includes/push_swap.h
    $(CC) $(CFLAGS) -c src/main.c -o main.o

sort_3.o: src/sort_3.c includes/push_swap.h
    $(CC) $(CFLAGS) -c src/sort_3.c -o sort_3.o

sort_4.o: src/sort_4.c includes/push_swap.h
    $(CC) $(CFLAGS) -c src/sort_4.c -o sort_4.o

sort_5.o: src/sort_5.c includes/push_swap.h
    $(CC) $(CFLAGS) -c src/sort_5.c -o sort_5.o

index.o: src/index.c includes/push_swap.h
    $(CC) $(CFLAGS) -c src/index.c -o index.o

utils.o: src/utils.c includes/push_swap.h
    $(CC) $(CFLAGS) -c src/utils.c -o utils.o

clean:
    @$(MAKE) -C ./libft clean
    @$(RM) $(OBJS)

fclean: clean
    @$(MAKE) -C ./libft fclean
    @$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
