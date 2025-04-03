/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:50:10 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 16:48:56 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}

/* int main() {
    const char *str = "Hello, World!";
    char ch = 'W';
    
    // Поиск символа 'o' в первых 10 байтах
    char *result = ft_memchr(str, ch, 10);

    if (result != NULL) {
        printf("Символ '%c' найден на позиции: %ld\n", ch, result - str);
    } else {
        printf("Символ '%c' не найден в первых 10 байтах.\n", ch);
    }

    return 0;
} */