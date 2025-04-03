/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:13 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:02:41 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*s2;
	int		i;

	len_s1 = 0;
	i = 0;
	while (s1[len_s1] != '\0')
	{
		len_s1++;
	}
	s2 = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (i < len_s1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/* int main()
{
	const char *s1 = "Hello, Alex!";
	char *s2 = ft_strdup(s1);
	printf("%s\n", s2);
} */