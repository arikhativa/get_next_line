/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 08:52:03 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/10 15:41:42 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NUMBER str[n] >= '0' && str[n] <= '9'

int		ft_atoi(const char *str)
{
	int res;
	int n;
	int neg;

	res = 0;
	n = 0;
	neg = 1;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t' || \
			str[n] == '\r' || str[n] == '\v' || str[n] == '\f')
		n++;
	if (str[n] == '-')
	{
		neg = -1;
		n++;
	}
	else if (str[n] == '+')
		n++;
	if (str[n] == '+' || str[n] == '-')
		return (0);
	while (NUMBER)
	{
		res = res * 10 + (str[n] - '0');
		n++;
	}
	return (res * neg);
}
