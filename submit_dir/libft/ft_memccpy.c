/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:14:30 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/20 19:07:07 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)dst;
	p2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		p1[i] = p2[i];
		if (p2[i] == (unsigned char)c)
			return (&p1[i + 1]);
		i++;
	}
	return (NULL);
}
