/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:00:06 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/21 15:59:14 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_make_line(const int fd, char **line, static char **sstr)
{
	size_t	n;
	char	*tmp;

	n = 0;
	while (sstr[fd][n] != '\n' && sstr[fd][n])
	   n++;
	if (sstr[fd][n] == '\n')
	{
		*line = ft_strsub(sstr[fd], 0, n);
		tmp = ft_strdup(sstr[fd] n + 1]);
		free(sstr[fd]);
		sstr[fd] = tmp;
		if (sstr[fd])
			ft_strdel(sstr[fd]);
	}
	else
	{
		*line = ft_strsub(sstr[fd], 0, n - 1);
		ft_strdel(sstr[fd]);
		free(sstr[fd]);
	}
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char	*sstr[100];
	int			ok;

	if (fd < 0 || kine == NULL)
		return (-1);
	while ((ok = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[BUFF_SIZE + 1] = '\0';
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
	if (ok == 0)
	{
		*line = sstr[fd];
		return (0);
	}
	ft_make_line(fd, line, sstr);
	return (1);

}
