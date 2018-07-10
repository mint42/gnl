/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:23 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/26 12:22:26 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define BUF(lst) (((t_file *)(lst->content))->buf)
# define FD(lst) (((t_file *)(lst->content))->fide)
# include "./libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_file
{
	char		*buf;
	int			fide;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
