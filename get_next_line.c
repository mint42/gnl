int		fill_line(t_lst lst, char **line, i)
{
	if (!line = (char *)malloc(BUFF_SIZE * i))
		return (0);
	while (--i)
	{
		strlcat(line, list->content);
		lst = lst->next;
	}
	while (lst->content[i] != '\n')
	{
		*line[i] == lst->content[i];
		++i;
	}
	line[i] = '\0';
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	t_list	*lst;
	t_list	*cur;
	int		i;

	if (fd < 0 || !line)
		return (-1);
	lst = ft_lstnew(0,0)
	cur = lst;
	i = 0;
	while (cur->content && cur)
	{
		bytes = read(fd, cur->content, BUFF_SIZE);
		if (bytes < 0)
			return (-1);
		if ((ft_strchr(cur->content, '\n') || bytes > BUFF_SIZE))
			return ((fill_line(lst, line, i) ? 1 : -1);
		cur = cur->next;
		cur->content = ft_strnew(BUFF_SIZE);
		++i;
	}
	if (!cur->content)
		ft_lstdel(lst);
	return (0); 
}
