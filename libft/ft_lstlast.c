/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:36:36 by alex              #+#    #+#             */
/*   Updated: 2024/10/12 12:52:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/* void	ft_create_list(t_list *node1, t_list *node2, t_list *node3)
{
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
}
int main()
{
	int *value1 = malloc(sizeof(int));
	*value1 = 1;
	t_list *node1 = ft_lstnew(value1); // создаем первый элемент

	int *value2 = malloc(sizeof(int));
	*value2 = 2;
	t_list *node2 = ft_lstnew(value2);

	int *value3 = malloc(sizeof(int));
	*value3 = 10;
	t_list *node3 = ft_lstnew(value3);

	ft_create_list(node1, node2, node3);
	
	t_list *last_node = ft_lstlast(node1);
	printf("%d\n", *(int *)last_node->content);
} */