/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:14 by rreedy            #+#    #+#             */
/*   Updated: 2018/08/31 15:54:50 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*stresize(char **s, int in, int size)
{
	char	*str;

	str = ft_strnew(size);
	if (!str)
		return (0);
	ft_strncpy(str, *s + in, size);
	ft_strdel(s);
	return (str);
}

static int		fill_line(char **line, char **s, int red)
{
	int			len;

	if (!*s)
		return (-1);
	if (!red && !ft_strlen(*s))
		return (0);
	len = ft_strchr(*s, '\n') ? ft_strchr(*s, '\n') - *s : (int)ft_strlen(*s);
	*line = ft_strnew(len);
	if (!*line || red == -1)
		return (-1);
	*line = ft_strncpy(*line, *s, len);
	*s = stresize(s, len + 1, BUFF_SIZE + (ft_strlen(*s) - len));
	return (*s ? 1 : -1);
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
		if (ft_strchr(BUF(lst), '\n') || red < BUFF_SIZE)
			return (fill_line(line, &BUF(lst), red));
		red = read(fd, BUF(lst) + ft_strlen(BUF(lst)), BUFF_SIZE);
		if (red == BUFF_SIZE)
			BUF(lst) = stresize(&BUF(lst), 0, ft_strlen(BUF(lst)) + BUFF_SIZE);
	}
	return (-1);
}
