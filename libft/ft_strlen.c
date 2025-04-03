/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:21:35 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:02:30 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* int main(void)
{
	printf("%zu\n", ft_strlen("000Hello1 ''223454321"));
	printf("%lu\n", strlen("000Hello1 ''223454321"));
	printf("%lu\n",sizeof (size_t)); // 8
	printf("%lu\n",sizeof (int)); // 4 WTF???
} */