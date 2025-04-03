/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:09 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/10 18:37:17 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*return_leer_str(void)
{
	char	*substr;

	substr = (char *)malloc(sizeof(char) * 1);
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	char			*substr;
	unsigned int	diff;
	unsigned int	index;

	index = 0;
	len_s = 0;
	while (s[len_s] != '\0')
		len_s++;
	if (start >= len_s)
		return (return_leer_str());
	diff = len_s - start;
	if (diff < (unsigned int)len)
		len = diff;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (index < len)
	{
		substr[index] = s[start + index];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

/* int main()
{
	char *str = "01234";

	char *substr = ft_substr(str, 10, 10);
	printf("%s\n", substr);
} */