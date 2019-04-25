/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:53:55 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/20 19:51:13 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*lim(int nbr)
{
	char *new;

	if (nbr != 0)
	{
		new = ft_strnew(12);
		new = ft_strcpy(new, "-2147483648");
	}
	else
	{
		new = ft_strnew(1);
		new = ft_strcpy(new, "0");
	}
	return (new);
}

static int		count(int n, int i)
{
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		putnbr(int n, char *s, int i)
{
	if (n / 10 != 0)
		putnbr(n / 10, s, i - 1);
	s[i] = (n % 10) + '0';
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n == -2147483648)
		return (lim(n));
	if (n == 0)
		return (lim(n));
	if (n < 0)
	{
		n = n * -1;
		i++;
		neg = 1;
	}
	i = count(n, i);
	if (!(s = ft_strnew(i)))
		return (NULL);
	putnbr(n, s, i - 1);
	if (neg)
		s[0] = '-';
	return (s);
}
