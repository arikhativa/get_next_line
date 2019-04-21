/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 09:23:27 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/10 15:22:04 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		size;
	int		a;

	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(sizeof(char) * (size + 1));
	size = 0;
	a = 0;
	while (s1[size])
	{
		new[size] = s1[size];
		size++;
	}
	while (s2[a])
	{
		new[size + a] = s2[a];
		a++;
	}
	new[size + a] = '\0';
	return (new);
}
