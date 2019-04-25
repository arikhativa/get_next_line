/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:00:06 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/24 10:51:16 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_make_line(int fd, char **line, char **sstr, int ok)
{
	int		n;
	char	*tmp;

	n = 0;
	while (sstr[fd][n] != '\n' && sstr[fd][n] != '\0')
		n++;
	if (sstr[fd][n] == '\n')
	{
		*line = ft_strsub(sstr[fd], 0, n);
		tmp = ft_strdup(sstr[fd] + n + 1);
		free(sstr[fd]);
		sstr[fd] = tmp;
		if (sstr[fd][0] == '\0')
			ft_strdel(&sstr[fd]);
	}
	else if (sstr[fd][n] == '\0')
	{
		if (ok == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(sstr[fd]);
		ft_strdel(&sstr[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*sstr[100];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ok;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((ok = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ok] = '\0';
		if (sstr[fd] == NULL)
			sstr[fd] = ft_strnew(1);
		tmp = ft_strjoin(sstr[fd], buff);
		free(sstr[fd]);
		sstr[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ok < 0)
		return (-1);
	else if (ok == 0 && (sstr[fd] == NULL || sstr[fd][0] == '\0'))
		return (0);
	return (ft_make_line(fd, line, sstr, ok));
}
