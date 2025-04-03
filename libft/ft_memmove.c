/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:23:49 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 17:18:14 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_memory(unsigned char *dest, const unsigned char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dest;
	const unsigned char		*serc;
	size_t					i;

	i = 0;
	dest = dst;
	serc = src;
	if (len == 0 || dest == serc)
		return (dst);
	if (dest < serc)
	{
		copy_memory(dest, serc, len);
	}
	else
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = serc[i - 1];
			i--;
		}
	}
	return (dst);
}

/* int main() {
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    
    // Перемещаем "World" в начало строки
    memmove(str1 + 7, str1 + 6, 6); // Копируем " World" (включая пробел)
    ft_memmove(str2 + 7, str2 + 6, 6); // Копируем " World" (включая пробел)
    
    printf("%s\n", str1); // Вывод: "Hello, World!"
    printf("%s\n", str2); // Вывод: "Hello, World!"
    
    return 0;
} */