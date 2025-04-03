/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:54:15 by omalovic          #+#    #+#             */
/*   Updated: 2024/12/31 15:38:17 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>

int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strlen(char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(char *haystack, char *needle, size_t len);
char			*ft_strrchr(char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				in_check(char const ch, char const *s);
unsigned int	len_str(char const *s);
int				find_i1(char const *s1, char const *set);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_mystrlen(char const *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*join_str(char const *s1, char const *s2, char *result);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				get_length(int n);
char			*ft_strdup(const char *s1);
char			*ft_strdup1(const char *s1);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
int				count_words(const char *s, char c);
int				get_word_length(const char **s, char c);
char			*get_next_word(const char **s, char c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			*double_value(void *content);
void			del_content(void *content);
int				process_node(t_list **new_list, t_list **current,
					void *new_content, void (*del)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif