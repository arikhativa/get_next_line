/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 09:58:51 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/20 19:07:20 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		w_count(const char *s, int n, char c)
{
	int w;

	w = 0;
	while (s[n])
	{
		if (s[n] != c && s[n])
		{
			while (s[n] != c && s[n])
				n++;
			w++;
		}
		while (s[n] == c)
			n++;
	}
	return (w);
}

static char		*substr(const char *s, int n, char c)
{
	int		l;
	char	*new;

	l = n;
	while (s[n] != c && s[n])
		n++;
	new = ft_strnew(n - l + 1);
	if (new == NULL)
		return (NULL);
	n = l;
	l = 0;
	while (s[n] != c && s[n])
	{
		new[l] = s[n];
		l++;
		n++;
	}
	new[l] = '\0';
	return (new);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**ms;
	int		n;
	int		w;

	if (!s)
		return (NULL);
	n = 0;
	while (s[n] == c)
		n++;
	w = w_count(s, n, c);
	ms = (char**)malloc(sizeof(char*) * (w + 1));
	if (ms == NULL)
		return (NULL);
	w = 0;
	while (s[n])
	{
		ms[w] = substr(s, n, c);
		w++;
		while (s[n] != c && s[n])
			n++;
		while (s[n] == c)
			n++;
	}
	ms[w] = NULL;
	return (ms);
}
