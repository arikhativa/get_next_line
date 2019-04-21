/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:14:30 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/10 15:34:04 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*p1;
	const char	*p2;

	p1 = dst;
	p2 = src;
	i = 0;
	if (ft_strlen(src) > ft_strlen(dst) || (int)n > ft_strlen(dst))
		return (NULL);
	while (i < n)
	{
		p1[i] = p2[i];
		if (p2[i] == (unsigned char)c)
			return (&p1[i + 1]);
		i++;
	}
	return (NULL);
}
