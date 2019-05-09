/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:13:48 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/11 11:30:02 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] == (char)n)
		return ((char*)(str + i));
	i = i - 1;
	while (i >= 0)
	{
		if (str[i] == (char)n)
			return ((char*)(str + i));
		i--;
	}
	return (NULL);
}
