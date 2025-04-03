/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:09:04 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 17:24:28 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	unsigned char	ch;

	ch = c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == ch)
	{
		return ((char *)s);
	}
	return (NULL);
}

/* int main() {
    char *str = "Hello, World!";
    char ch = 'o';

    char *result = ft_strchr(str, ch);

    if (result != NULL) {
        printf("Символ '%c' найден на позиции: %ld\n", ch, result - str);
    } else {
        printf("Символ '%c' не найден в строке.\n", ch);
    }

    return 0;
} */