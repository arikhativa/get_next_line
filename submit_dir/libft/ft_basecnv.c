/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basecnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 09:55:45 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/25 14:14:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num(char nbr, int base)
{
	int		i;
	char	*lst;

	i = 0;
	lst = ft_strdup("0123456789abcdef");
	while (lst[i] && i < base)
	{
		if (lst[i] == ft_tolower(nbr))
			return (i);
		i++;
	}
	return (-1);
}

static int	valid_nbr(char *nbr, int base)
{
	int i;

	i = 0;
	if (nbr[0] == '-')
		i = 1;
	while (nbr[i])
	{
		if (get_num(nbr[i], base) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int			ft_basecnv(char *nbr, int base)
{
	int len;
	int res;
	int i;
	int neg;

	if ((!nbr) || (valid_nbr(nbr, base) == -1))
		return (-1);
	i = 0;
	if (nbr[0] == '-')
		i = 1;
	res = 0;
	neg = i;
	if (base > 16 || base < 2)
		return (-1);
	len = ft_strlen(nbr + i);
	while (nbr[i])
	{
		res = res + (get_num(nbr[i], base) * ft_power(base, len - 1));
		i++;
		len--;
	}
	if (neg == 1)
		res = res * (-1);
	return (res);
}
