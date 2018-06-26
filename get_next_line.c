#include "get_next_line.h"

static int		fill_line(t_list *lst, char **line, int len)
{
	BUF(lst) = BUF(lst) + len;
	if (!(*line = (char *)malloc(len)))
		return (-1);
	len = 0;
	while (*BUF(lst) != '\n')
		--BUF(lst);
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
		ft_putendl(BUF(lst));
		BUF(lst) = ft_realloc(BUF(lst), ft_strlen(BUF(lst)) + BUFF_SIZE);
	}
	return (-1); 
}
