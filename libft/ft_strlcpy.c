/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:54:07 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:02:34 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (dstsize > 0)
	{
		i = 0;
		while (i < len_src && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

/* int main() {
    const char *src1 = "Hello, World!";
    char dst1[13];

	const char *src2 = "Hello, World!";
    char dst2[10];

    // Копирование строки с использованием strlcpy
    size_t result1 = strlcpy(dst1, src1, sizeof(dst1));
    size_t result2 = strlcpy(dst2, src2, sizeof(dst2));

    // Вывод результата
    printf("Скопированная строка: '%s'\n", dst1);
    printf("Общая длина строки src: %zu\n", result1);

	printf("Скопированная строка: '%s'\n", dst2);
    printf("Общая длина строки src: %zu\n", result2);
} */