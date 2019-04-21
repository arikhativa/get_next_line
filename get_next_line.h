/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:00:57 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/18 14:30:18 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4000
# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

int		get_next_line(const int fd, char **line);

#endif
