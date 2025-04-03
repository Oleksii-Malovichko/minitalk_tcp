/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:27:44 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 17:27:47 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char			*pc;
	unsigned char	ch;

	ch = c;
	pc = NULL;
	while (*s)
	{
		if (*s == ch)
		{
			pc = s;
		}
		s++;
	}
	if (*s == ch)
	{
		return ((char *)s);
	}
	return ((char *)pc);
}

/* int main() {
    char *str = "wwwwwwwwwww";

    char *first = strchr(str, 'w');
    char *last = ft_strrchr(str, 'w');

    if (first != NULL) {
        printf("Первое вхождение 'o' найдено на позиции: %ld\n", first - str);
    } else {
        printf("'o' не найдено.\n");
    }

    if (last != NULL) {
        printf("Последнее вхождение 'o' найдено на позиции: %ld\n", last - str);
    } else {
        printf("'o' не найдено.\n");
    }

    return 0;
} */