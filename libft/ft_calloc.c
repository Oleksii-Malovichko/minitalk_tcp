/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:27:11 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:03:45 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	i = 0;
	total_size = count * size;
	ptr = (void *) malloc (total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	byte_ptr = ptr;
	while (i < total_size)
	{
		byte_ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

/* int main() {
    int n = 5;
    // Выделяем память с помощью my_calloc
    int* array = (int*)ft_calloc(n, sizeof(int));

    if (array == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // Используем массив
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]); // Все элементы будут равны 0
    }
    printf("\n");

    // Освобождаем память
    free(array);

    return 0;
} */