/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:35:18 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 18:27:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4094
# endif

# ifndef ERROR
#  define ERROR			-1
# endif

# ifndef SUCCESS
#  define SUCCESS		1
# endif

# define NL_CHAR		'\n'
# define END_OF_FILE	0

char	*get_next_line(int fd);

#endif
