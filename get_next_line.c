/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:35:23 by yoav              #+#    #+#             */
/*   Updated: 2022/06/29 10:03:18 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TODO remove
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

char	*split_str(char **origin, size_t i)
{
	char	*tmp;
	char	*ret;

	ret = ft_strndup(*origin, i);
	if (!ret)
		return (NULL);
	tmp = ft_strndup((*origin) + i, ft_strlen(*origin) - i);
	if (!tmp)
	{
		free(ret);
		return (NULL);
	}
	swap_ptr(&tmp, origin);
	free(tmp);
	return (ret);
}

char	*create_line(char **buff)
{
	char	*ret;
	char	*runner;
	size_t	i;

	ret = NULL;
	runner = *buff;
	while (*runner && NL_CHAR != *runner)
		++runner;
	if (NL_CHAR == *runner)
	{
		i = runner - *buff + 1;
		ret = split_str(buff, i);
		return (ret);
	}
	return (NULL);
}

ssize_t	extened_buffer(int fd, char **buff)
{
	char		*new_buff;
	char		*tmp;
	ssize_t		stt;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ERROR);
	stt = read(fd, tmp, BUFFER_SIZE);
	if (0 >= stt)
	{
		free(tmp);
		return (stt);
	}
	tmp[stt] = '\0';
	new_buff = ft_join_str(*buff, tmp);
	if (!new_buff)
		return (ERROR);
	*buff = new_buff;
	return (SUCCESS);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*ret;
	ssize_t		stt;

	if (NULL == buff)
	{
		buff = ft_strndup("", 1);
		if (!buff)
			return (NULL);
	}
	stt = ERROR;
	ret = create_line(&buff);
	while (!ret && END_OF_FILE != stt)
	{
		stt = extened_buffer(fd, &buff);
		if (ERROR == stt)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		ret = create_line(&buff);
	}
	if (END_OF_FILE == stt && 0 != ft_strlen(buff))
	{
		ret = buff;
		buff = NULL;
	}
	else if (END_OF_FILE == stt && 0 == ft_strlen(buff))
	{
		free(buff);
		buff = NULL;
		ret = NULL;
	}
	return (ret);
}
