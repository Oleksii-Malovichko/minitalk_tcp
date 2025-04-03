/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:25:26 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/10 18:07:48 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_str(char const *s1, char const *s2, char *result)
{
	unsigned int	index;
	unsigned int	len_s;

	index = 0;
	len_s = 0;
	while (s1[len_s] != '\0')
	{
		result[len_s] = s1[len_s];
		len_s++;
	}
	while (s2[index] != '\0')
	{
		result[len_s] = s2[index];
		index++;
		len_s++;
	}
	result[len_s] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	len_s;
	unsigned int	general_len;

	if (!s1 || !s2)
		return (NULL);
	general_len = 0;
	len_s = 0;
	while (s1[len_s] != '\0')
		len_s++;
	while (s2[general_len] != '\0')
		general_len++;
	general_len = len_s + general_len;
	result = (char *)malloc(sizeof(char) * (general_len + 1));
	if (!result)
		return (NULL);
	return (join_str(s1, s2, result));
}

/* int main()
{
	char *s1 = "Hello++__";
	char *s2 = "world!1234";
	printf("%s\n", ft_strjoin(s1, s2));
} */