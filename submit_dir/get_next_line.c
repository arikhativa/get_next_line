/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:00:06 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/26 10:08:19 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	alloc_line(const int fd, char **line, char **str)
{
	int		n;
	char	*tmp;

	n = 0;
	while (str[fd][n] != '\n' && str[fd][n] != '\0')
		n++;
	if (str[fd][n] == '\n')
	{
		*line = ft_strsub(str[fd], 0, n);
		tmp = ft_strdup(str[fd] + n + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][n] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ok;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*str[100];

	if (fd < 0 || line == NULL)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	while ((ok = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[BUFF_SIZE] = '\0';
		tmp = ft_strjoin(str[fd], buf);
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
