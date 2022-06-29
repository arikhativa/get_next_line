/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:35:25 by yoav              #+#    #+#             */
/*   Updated: 2022/06/29 10:03:59 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

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

void	swap_ptr(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
