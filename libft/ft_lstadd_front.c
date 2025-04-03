/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:43:19 by alex              #+#    #+#             */
/*   Updated: 2024/10/12 12:29:37 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* int main()
{
	int *value1 = malloc(sizeof(int));
	*value1 = 1;
	t_list *node1 = ft_lstnew(value1); // создаем первый элемент

	int *value2 = malloc(sizeof(int));
	*value2 = 2;
	t_list *node2 = ft_lstnew(value2);

	ft_lstadd_front(&node1, node2);

	while (node1)
	{
		printf("%d\n", *(int *)node1->content);
		node1 = node1->next;
	}
	// free(value1);
    // free(node1);
    // free(value2);
    // free(node2);
} */