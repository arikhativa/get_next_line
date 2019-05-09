/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:13:03 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/06 13:45:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t i)
{
	size_t n;
	size_t a;

	n = 0;
	a = 0;
	while (dst[n])
		n++;
	while (src[a] && a < i)
	{
		dst[n + a] = src[a];
		a++;
	}
	dst[n + a] = '\0';
	return (dst);
}
