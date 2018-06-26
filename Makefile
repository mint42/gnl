# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 14:10:26 by rreedy            #+#    #+#              #
#    Updated: 2018/06/26 14:17:44 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gnl
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
INCLUDE_DIR := ./libft/includes
CFLAGS := -Wall -Wextra -Werror -I$(INCLUDE_DIR)
LDFLAGS := -L./libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	@- $(RM) $(OBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
