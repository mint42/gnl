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

static int		fill_line(t_list *lst, char **line, int len)
{
	BUF(lst) = BUF(lst) + ft_strlen(BUF(lst));
	if (!(*line = (char *)malloc(len)))
		return (-1);
	len = 0;
	while (*BUF(lst) != '\n')
		--BUF(lst);
	ft_putendl(BUF(lst));
	while (++BUF(lst) && *BUF(lst) != '\n')
	{
		*line = BUF(lst);
		++(*line);
	}
	**line = '\0';
	return (1);
}

static char	*ft_realloc(char *s, int size)
{
	return (ft_strcpy((char *)malloc(size), s));
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

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				len;

	if (!fd || fd < 0 || !line)
		return (-1);
	while (lst && lst->content)
	{
		if (FD(lst) == fd)
			break;
		lst = lst->next;
	}
	if (!lst)
		lst = ft_lstnew(0,0);
	if (!lst->content)
		lst->content = newfile(fd);
	while (BUF(lst))
	{
		len = ft_strlen(BUF(lst));
		if (!read(fd, BUF(lst) + len, BUFF_SIZE))
			return (0);
		if (ft_strchr(BUF(lst) + len, '\n'))
			return (fill_line(lst, line, len));
		BUF(lst) = ft_realloc(BUF(lst), len + BUFF_SIZE);
	}
	return (-1); 
}
