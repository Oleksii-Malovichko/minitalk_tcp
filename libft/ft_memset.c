/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:28:42 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:02:48 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (b);
}

/* int main()
{
	char str1[55] = "Hello, world!";
	char str2[55] = "Hello, world!";
	printf("Before: %s\n", str1);
	printf("Before: %s\n", str2);
	ft_memset(str1, 'B', 65);
	memset(str2, 'A', 65);
	printf("After: %s\n", str1);
	printf("After: %s\n", str2);

} */