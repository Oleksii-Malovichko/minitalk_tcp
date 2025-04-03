/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:55:34 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/10 18:48:28 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_check(char const ch, char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

unsigned int	len_str(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	find_i1(char const *s1, char const *set)
{
	unsigned int	i1;

	i1 = 0;
	while (s1[i1] != '\0')
	{
		if (!in_check(s1[i1], set))
			break ;
		i1++;
	}
	return (i1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i1;
	unsigned int	i2;
	int				index;
	char			*result;

	i2 = len_str(s1);
	i1 = find_i1(s1, set);
	index = 0;
	while (i2 > i1)
	{
		if (!in_check(s1[i2 - 1], set))
			break ;
		i2--;
	}
	result = (char *)malloc(sizeof(char) * (i2 - i1 + 1));
	if (!result)
		return (NULL);
	while (i1 < i2)
		result[index++] = s1[i1++];
	result[index] = '\0';
	return (result);
}

/* int main()
{
	const char *str = "+++--=Hel-+lo=+-+";
	// const char *str = "=+-+";

	const char *set = "+";
	printf("%s\n", ft_strtrim(str, set));
} */