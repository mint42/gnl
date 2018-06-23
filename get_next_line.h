#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
#include "libft/libft.h"

int		fill_line(t_list lst, char **line, int i);
int		get_next_line(const int fd, char **line);

#endif
