/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:00:06 by yrabby            #+#    #+#             */
/*   Updated: 2019/05/15 12:31:42 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int	is_nw(const int fd, char **line, char **str, int n)
{
	char	*tmp;

	if (!(*line = ft_strsub(str[fd], 0, n)))
		return (-1);
	if (!(tmp = ft_strdup(str[fd] + n + 1)))
		return (-1);
	free(str[fd]);
	str[fd] = tmp;
	if (str[fd][0] == '\0')
		ft_strdel(&str[fd]);
	return (1);
}

static int	alloc_line(const int fd, char **line, char **str)
{
	int		n;

	n = 0;
	while (str[fd][n] != '\n' && str[fd][n] != '\0')
		n++;
	if (str[fd][n] == '\n')
	{
		if (is_nw(fd, line, str, n) == -1)
			return (-1);
	}
	else if (str[fd][n] == '\0')
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ok;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*str[MAX_FD];

	if (fd > MAX_FD || fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (str[fd] == NULL && (!(str[fd] = ft_strnew(1))))
		return (-1);
	while ((ok = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ok] = '\0';
		if (!(tmp = ft_strjoin(str[fd], buf)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	if (ok == -1)
		return (-1);
	if (ok == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (alloc_line(fd, line, str));
}
