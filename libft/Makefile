# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/31 16:53:28 by rreedy            #+#    #+#              #
#    Updated: 2018/08/31 18:12:03 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

COBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
CFLAGS := -Wall -Wextra -Werror -I./includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(COBJS)
	ar rc $(NAME) $(COBJS)
	ranlib $(NAME)

clean:
	@- $(RM) $(COBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
