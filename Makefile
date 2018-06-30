NAME := getline
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

