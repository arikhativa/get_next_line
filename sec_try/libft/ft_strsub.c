/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 09:32:50 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/20 19:07:31 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	n;

	if (!s)
		return (NULL);
	n = 0;
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	while (n < len)
	{
		new[n] = s[start + n];
		n++;
	}
	return (new);
}
