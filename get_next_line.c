/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:14 by rreedy            #+#    #+#             */
/*   Updated: 2018/07/12 16:46:18 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char		*ft_realloc(char *s, int in, int size)
{
	char	*str;

	str = ft_strnew(size);
	if (!str)
		return (0);
	ft_strncpy(str, s + in, size);
	ft_strdel(&s);
	return (str);
}

static int		fill_line(char **line, char **str, int red)
{
	int		len;

	if (!*str)
		return (-1);
	if (!red && !ft_strlen(*str))
		return (0);
	*line = ft_strnew(ft_strlen(*str));
	len = ft_strchr(*str, '\n') ? ft_strchr(*str, '\n') - *str : BUFF_SIZE;
	if (!*line || red == -1)
		return (-1);
	*line = ft_strncpy(*line, *str, len);
	*str = ft_realloc(*str, len + 1, BUFF_SIZE + (ft_strlen(*str) - len));
//	*str = ft_strsub(*str, len + 1, BUFF_SIZE + (ft_strlen(*str) - len));
	return (*str ? 1 : -1);
}

static int		get_file(t_list **lst, int fd)
{
	t_file	*newf;

	if (!(*lst))
		return (-1);
	while ((*lst)->content && (((t_file *)((*lst)->content))->fide != fd))
	{
		if (!(*lst)->next)
			(*lst)->next = ft_lstnew(0, 0);
		*lst = (*lst)->next;
	}
	if (!((*lst)->content))
	{
		if (!(newf = (t_file *)ft_memalloc(sizeof(t_file))))
			return (-1);
		if (!(newf->buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		newf->fide = fd;
		(*lst)->content = newf;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	int				red;
	int				len;

	red = BUFF_SIZE + 1;
	if (fd < 0 || !line)
		return (-1);
	if (!head)
		head = ft_lstnew(0, 0);
	lst = head;
	if (get_file(&lst, fd) == -1)
		return (-1);
	while (BUF(lst))
	{
		len = ft_strlen(BUF(lst));
		if (ft_strchr(BUF(lst), '\n') || red < BUFF_SIZE)
			return (fill_line(line, &BUF(lst), red));
		if (BUFF_SIZE == (red = read(fd, BUF(lst) + len, BUFF_SIZE)))
			BUF(lst) = ft_realloc(BUF(lst), 0, ft_strlen(BUF(lst)) + BUFF_SIZE);
	}
	return (-1);
}
