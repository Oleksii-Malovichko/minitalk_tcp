/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:56:47 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/10 18:07:52 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* void to_upper(unsigned int index, char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c -= 32; // Преобразуем строчные буквы в заглавные
    }
}
int main() {
    char str[] = "hello world";

    // Применяем ft_striteri к строке
    ft_striteri(str, to_upper);

    printf("Transformed: %s\n", str); // Вывод: "HELLO WORLD"

    return 0;
} */