#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("./EXAMPLE_MAIN.c", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
