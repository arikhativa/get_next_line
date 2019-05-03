/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:31:30 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/11 11:17:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)n)
			return ((char*)(str + i));
		i++;
	}
	if (str[i] == (char)n)
		return ((char*)(str + i));
	return (NULL);
}
