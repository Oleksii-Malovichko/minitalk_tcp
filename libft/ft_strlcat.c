/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:17:14 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:45:58 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	i = 0;
	len_dst = 0;
	len_src = 0;
	while (dst[len_dst] != '\0' && len_dst < dstsize)
		len_dst++;
	while (src[len_src] != '\0')
	{
		len_src++;
	}
	if (dstsize == 0)
		return (len_src);
	if (len_dst >= dstsize)
		return (len_src + dstsize);
	while (src[i] != '\0' && (len_dst + i) < (dstsize - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/* int main() {
    char dst[12] = "Hello, ";
    const char *src = "World!";

    size_t result = ft_strlcat(dst, src, sizeof(dst));

    printf("Результат: '%s'\n", dst);
    printf("Общая длина строки: %zu\n", result);

    if (result >= sizeof(dst)) {
        printf("Предупреждение: целевой буфер слишком мал!\n");
		printf("Result %zu\n", result);
    }

    return 0;
} */