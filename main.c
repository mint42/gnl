#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd1;
//	int		fd2;
	char	*line;

	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
//	fd2 = open(argv[2], O_RDONLY);
	if (get_next_line(fd1, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
//	if (get_next_line(fd2, &line))
//	{
//		ft_putendl(line);
//		ft_strdel(&line);
//	}
	return (0);
}
