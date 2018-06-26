NAME := gnl
CFLAGS := -Wall -Wextra -Werror
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -I ./libft $(SRCS) -L./libft -lft

clean:
	@- $(RM) $(OBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all

