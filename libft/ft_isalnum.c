/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:43:43 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:03:39 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (48 <= c && c <= 57)
	{
		return (1);
	}
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
	{
		return (1);
	}
	return (0);
}

/* int main(void)
{
    printf("%d\n", ft_isalnum(':'));
    printf("%d\n", isalnum(':'));
} */