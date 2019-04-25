/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:56:51 by yrabby            #+#    #+#             */
/*   Updated: 2019/04/25 15:10:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t i);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strchr(const char *str, int n);
char			*ft_strrchr(const char *str, int n);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t i);
size_t			ft_strlcat(char *dst, const char *src, size_t i);
void			*ft_memset(void *ptr, int n, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_toupper(int n);
int				ft_tolower(int n);
void			ft_bzero(void *str, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_putendl(const char *str);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_strclr(char *s);
void			ft_strdel(char **tab);
void			ft_memdel(void **tab);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char*s);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(int n);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
t_list			*ft_lstnew(void const *c, size_t s);
void			ft_lstadd(t_list **alist, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_intcount(int nbr);
int				ft_isprime(unsigned int nbr);
int				ft_lstlen(t_list *lst);
int				ft_power(int nbr, int power);
int				ft_basecnv(char *nbr, int base);

#endif
