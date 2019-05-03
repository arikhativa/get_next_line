/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 09:44:37 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/21 15:06:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SPACE s[n] == ' ' || s[n] == '\n' || s[n] == '\t'

static int	is_only_space(const char *s)
{
	int n;

	n = 0;
	while (SPACE)
		n++;
	if (n == (int)ft_strlen(s))
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	char			*new;
	unsigned int	n;
	size_t			len;

	if (!s)
		return (NULL);
	if (is_only_space(s))
		new = ft_strsub(s, 0, 0);
	else
	{
		n = (unsigned int)(ft_strlen(s) - 1);
		while (SPACE)
			n--;
		len = n;
		n = 0;
		while (SPACE)
			n++;
		new = ft_strsub(s, n, (len - n) + 1);
	}
	if (new == NULL)
		return (NULL);
	return (new);
}
