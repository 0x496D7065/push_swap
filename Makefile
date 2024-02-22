# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:46:17 by lpetit            #+#    #+#              #
#    Updated: 2024/02/22 15:20:31 by lpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

INCLUDES = -L./includes

LIBFT = includes/libft.a

CC = gcc

SRCS_DIR = ./srcs/

SRCS= $(SRCS_DIR)exit_msg.c $(SRCS_DIR)ft_stack.c $(SRCS_DIR)swap.c \
	$(SRCS_DIR)push.c $(SRCS_DIR)rotate.c $(SRCS_DIR)string_init.c \
	$(SRCS_DIR)helper.c $(SRCS_DIR)sort.c $(SRCS_DIR)cost_analysis.c \
	$(SRCS_DIR)target_init.c $(SRCS_DIR)main.c

OBJS= $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I./includes

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	$(MAKE) -C ./includes

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) -lftprintf -lft


clean:
	$(MAKE) -C ./includes clean
	rm -rf $(OBJS)

fclean:	clean
	$(MAKE) -C ./includes fclean
	rm -rf $(NAME)

re:	fclean all
