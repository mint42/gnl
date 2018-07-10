/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:14 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/26 16:07:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char		*ft_realloc(char *s, int size)
{
	char	*str;

	str = ft_strnew(size);
	ft_strncpy(str, s, size);
	ft_strdel(&s);
	return (str);
}

static int		fill_line(char	**line, char **str, int red)
{
	int		len;

	if (!*str)
		return (-1);
	else if (ft_strlen(*str) == 0)
		return (0);
	*line = ft_strnew(ft_strlen(*str));
	len = ft_strchr(*str, '\n') ? ft_strchr(*str, '\n') - *str : BUFF_SIZE;
	if (!*line || red == -1)
		return (-1);
	*line = ft_strncpy(*line, *str, len);
	if (ft_strlen(*str) - len)
		*str = ft_strsub(*str, len + 1, BUFF_SIZE + (ft_strlen(*str) - len));
	else
		return (0);
	return (*str ? 1 : 0);
}

static t_file	*newfile(int fd)
{
	t_file	*newf;

	newf = (t_file *)ft_memalloc(sizeof(t_file));
	if (!newf)
		return (0);
	newf->fide = fd;
	newf->buf = ft_strnew(BUFF_SIZE);
	return (newf);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				red;
	int				len;

	red = BUFF_SIZE + 1;
	if (fd < 0 || !line)
		return (-1);
	while (lst && lst->content && FD(lst) != fd)
		lst = lst->next;
	if (!lst)
		lst = ft_lstnew(0,0);
	if (!lst->content)
		lst->content = newfile(fd);
	while (BUF(lst))
	{	
		len = ft_strlen(BUF(lst));
		if (ft_strchr(BUF(lst), '\n') || red < BUFF_SIZE)
			return (fill_line(line, &BUF(lst), red));
		red = read(fd, BUF(lst) + len, BUFF_SIZE);
		BUF(lst) = ft_realloc(BUF(lst), ft_strlen(BUF(lst)) + BUFF_SIZE);
	}
	return (-1);
}
