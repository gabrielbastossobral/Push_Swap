# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 17:04:56 by gabrielsobr       #+#    #+#              #
#    Updated: 2025/01/10 12:59:13 by gabrielsobr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCDIR = src
INCDIR = includes
LIBDIR = libft
UTIDIR = utils

SRCS = $(SRCDIR)/main.c \
		$(SRCDIR)/push.c \
		$(SRCDIR)/radix_sort.c \
		$(SRCDIR)/reverse_rotate.c \
		$(SRCDIR)/rotate.c \
		$(SRCDIR)/simple_sort.c \
		$(SRCDIR)/sort.c \
		$(SRCDIR)/swap.c
OBJS_SRCS = $(SRCS:.c=.o)

UTILS = $(UTIDIR)/check_args.c \
		$(UTIDIR)/index.c \
		$(UTIDIR)/list_utils_2.c \
		$(UTIDIR)/list_utils.c \
		$(UTIDIR)/utils.c
OBJS_UTILS = $(UTILS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCDIR) -I$(LIBDIR)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS_SRCS) $(OBJS_UTILS)
	@$(MAKE) -C $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJS_SRCS) $(OBJS_UTILS) $(LIBDIR)/libft.a -o $(NAME)

%.o: %.c $(INCDIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBDIR) clean
	$(RM) $(OBJS_SRCS) $(OBJS_UTILS)

fclean: clean
	@$(MAKE) -C $(LIBDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
