/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:41:16 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 16:42:14 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while (i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 == '\0' || c2 == '\0' || c1 != c2)
		{
			return (c1 - c2);
		}
		i++;
	}
	return (0);
}

/* int main() {
    // const char *str1 = "Hello, World!";
    // const char *str2 = "Hello, everyone!";
    
    int result = ft_strncmp(NULL, NULL, 0); // Сравниваем первые 5 символов

    printf("%d\n", result);

    return 0;
} */