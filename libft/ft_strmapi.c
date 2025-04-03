/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:40:36 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/10 18:19:18 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mystrlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*result;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_mystrlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* char to_upper(unsigned int index, char c)
{
	return (c >= 'a' && c <= 'z') ? c - 32 : c;
}// delete later
int main() {
    char *original = "hello world";
    char *result = ft_strmapi(original, to_upper);
    if (result) {
        printf("Original: %s\n", original);
        printf("Transformed: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed\n");
    }
} */