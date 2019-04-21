/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:36:20 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/11 10:49:40 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*p1;
	const char	*p2;

	p1 = dst;
	p2 = src;
	i = 0;
	if (p1 > p2)
	{
		while (n > 0)
		{
			n--;
			p1[n] = p2[n];
		}
	}
	else
	{
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	return (dst);
}
