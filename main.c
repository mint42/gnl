/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:00:49 by rreedy            #+#    #+#             */
/*   Updated: 2018/07/10 16:00:58 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int		fd1;
	char	*line;
	int		ret;

	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
	ret = get_next_line(fd1, &line);
	while (ret)
	{
		ft_putnbr(ret);
		ft_putendl(line);
		ft_strdel(&line);
		ret = get_next_line(fd1, &line);
	}
	ft_putnbr(ret);
	return (0);
}
