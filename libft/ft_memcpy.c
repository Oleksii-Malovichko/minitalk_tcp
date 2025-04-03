/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:07:48 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 17:16:26 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*serc;

	dest = (unsigned char *)dst;
	serc = (const unsigned char *)src;
	if (n == 0 || dest == serc)
		return (dst);
	i = 0;
	while (i < n)
	{
		dest[i] = serc[i];
		i++;
	}
	return (dst);
}

/* int main() {
    // char src1[] = "Hello, World!";
    // char dest1[20];
    char src2[] = "Hello, World!";
    char dest2[20];

	ft_memcpy(dest2, src2, 0);
    // memcpy(dest1, src1, 0);
    // printf("%s\n", dest1); // Вывод: Hello, World!
    printf("%s\n", dest2); // Вывод: Hello, World!
} */