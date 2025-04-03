/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:31 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:03:51 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/* int main(void)
{
	char str1[50] = "Hello, world!";
	char str2[50] = "Hello, world!";
	ft_bzero(str1, 5);
	bzero(str2, 5);
	for (int i = 0; i < 12; i++)
	{
		printf("%c", str2[i]);
	}
	printf("\n");

	for (int i = 0; i < 12; i++)
	{
		printf("%c", str1[i]);
	}
	printf("\n");
} */