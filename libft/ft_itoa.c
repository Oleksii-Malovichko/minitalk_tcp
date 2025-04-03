/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:35:50 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/13 14:44:12 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_length(int n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		length++;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	if (length == 0)
		return (1);
	return (length);
}

char	*ft_strdup1(const char *s1)
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

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	if (n == -2147483648)
		return (ft_strdup1("-2147483648"));
	length = get_length(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	if (n == 0)
		result[0] = '0';
	length--;
	while (n > 0)
	{
		result[length] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	return (result);
}

/* int main()
{
	int number = 0;
	printf("%s\n", ft_itoa(number));
	// ft_itoa(number);
	// write(1, "\n", 1);
} */