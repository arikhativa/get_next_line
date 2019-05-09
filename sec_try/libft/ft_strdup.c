/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:06:10 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/10 15:20:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		n;
	char	*new;

	n = ft_strlen(str);
	if (!(new = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	n = 0;
	while (str[n])
	{
		new[n] = str[n];
		n++;
	}
	new[n] = '\0';
	return (new);
}
