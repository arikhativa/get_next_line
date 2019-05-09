/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:06:07 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/11 11:49:15 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int n;

	n = 0;
	while (s2[n] && s1[n] && (unsigned char)s1[n] == (unsigned char)s2[n])
		n++;
	return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}
