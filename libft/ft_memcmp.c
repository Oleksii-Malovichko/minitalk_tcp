/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:09:12 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:03:03 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/* int main()
{
	const char str1[] = "Hello, World!";
    const char str2[] = "Hello, World!";
    const char str3[] = "Hello, everyone!";
    
    int result1 = ft_memcmp(str1, str2, sizeof(str1)); // Сравниваем str1 и str2
    int result2 = ft_memcmp(str1, str3, sizeof(str1)); // Сравниваем str1 и str3

    if (result1 == 0) {
        printf("str1 и str2 равны.\n");
    } else {
        printf("str1 и str2 не равны.\n");
    }

    if (result2 == 0) {
        printf("str1 и str3 равны.\n");
    } else {
        printf("str1 и str3 не равны.\n");
    }
} */