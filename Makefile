# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:46:17 by lpetit            #+#    #+#              #
#    Updated: 2024/01/05 13:15:14 by lpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap.out

INCLUDES = -L./includes

SRCS_DIR = ./srcs/

SRCS= $(SRCS_DIR)exit_msg.c $(SRCS_DIR)ft_stack.c $(SRCS_DIR)swap.c \
	$(SRCS_DIR)push.c $(SRCS_DIR)rotate.c $(SRCS_DIR)string_init.c \
	$(SRCS_DIR)helper.c $(SRCS_DIR)sort.c $(SRCS_DIR)cost_analysis.c \
	$(SRCS_DIR)target_init.c $(SRCS_DIR)main.c

OBJS= $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I./includes

.PHONY: all clean fclean re

all: $(NAME)
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) -lftprintf -lft

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)
