/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:35:23 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 19:09:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TODO remove
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

char	*get_new_line(char *s)
{
	while (*s)
	{
		if (NL_CHAR == *s)
			return (s);
		++s;
	}
	return (NULL);
}

int	should_stop(ssize_t read_stt, char *buff)
{
	if (get_new_line(buff))
		return (1);
	if (0 >= read_stt)
		return (1);
	return (0);
}

char	*ft_strndup(char *s, size_t size)
{
	size_t	i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		ret[i] = s[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

void	swap_ptr(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*split_str(char **origen, size_t len)
{
	size_t	i;
	char	*tmp;
	char	*ret;

	ret = ft_strndup(*origen, len + 1);
	if (!ret)
		return (NULL);
	tmp = ft_strndup((*origen) + len + 1, -1);
	if (!tmp)
	{
		free(ret);
		return (NULL);
	}
	swap_ptr(&tmp, origen);
	free(tmp);
	return (ret);
}

char	*create_line(char **buff)
{
	char	*ret;
	char	*runner;
	size_t	len;

	ret = NULL;
	runner = *buff;
	while (*runner && NL_CHAR != *runner)
		++runner;
	if (NL_CHAR == *runner)
	{
		len = runner - *buff + 1;
		ret = split_str(buff, len);
		return (ret);
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_memcpy(char *d, char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		d[i] = s[i];
		++i;
	}
}

char	*ft_join_str(char *a, char *b)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = ft_strlen(a);
	j = ft_strlen(b);
	ret = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, a, i);
	ft_memcpy((ret + i), b, j);
	ret[i + j] = '\0';
	free(a);
	free(b);
	return (ret);
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
	new_buff = ft_join_str(tmp, *buff);
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
	return (ret);
}
