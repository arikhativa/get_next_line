/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:03:20 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/06 13:49:04 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t z;

	if (!(*s2))
		return ((char*)s1);
	i = 0;
	z = 0;
	while (s1[i] && (i - 1 + ft_strlen(s2)) < n)
	{
		while (s1[i + z] == s2[z])
		{
			if (s2[z + 1] == '\0')
				return ((char*)(s1 + i));
			z++;
		}
		z = 0;
		i++;
	}
	return (NULL);
}
