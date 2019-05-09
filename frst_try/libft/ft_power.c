/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:09:27 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/25 12:26:32 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		limit(int power)
{
	int lim;

	if (power > 30)
		lim = 0;
	else if (power > 19)
		lim = 2;
	else if (power > 15)
		lim = 3;
	else if (power > 13)
		lim = 4;
	else if (power > 11)
		lim = 5;
	(power == 11) ? lim = 7 : (lim);
	(power == 10) ? lim = 8 : (lim);
	(power == 9) ? lim = 10 : (lim);
	(power == 8) ? lim = 14 : (lim);
	(power == 7) ? lim = 21 : (lim);
	(power == 6) ? lim = 35 : (lim);
	(power == 5) ? lim = 73 : (lim);
	(power == 4) ? lim = 215 : (lim);
	(power == 3) ? lim = 1290 : (lim);
	(power == 2) ? lim = 46340 : (lim);
	return (lim);
}

static int		action(int nbr, int power)
{
	int i;

	i = 1;
	if (power > 0)
		i = nbr * (action(nbr, power - 1));
	return (i);
}

int				ft_power(int nbr, int power)
{
	int lim;

	if (power == 1)
		return (nbr);
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	lim = limit(power);
	if (nbr > lim || nbr < (-1 * lim))
		return (0);
	return (action(nbr, power));
}
