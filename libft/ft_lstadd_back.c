/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:53:04 by alex              #+#    #+#             */
/*   Updated: 2024/10/16 13:08:08 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		current = *lst;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
	}
}

/* void	ft_create_list(t_list *node1, t_list *node2, t_list *node3)
{
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
}
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
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
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

	ft_create_list(node1, node2, node3); // создали список
	
	int *value4 = malloc(sizeof(int));
	*value4 = 200;
	t_list *node4 = ft_lstnew(value4); // новый узел для добавления в конец
	
	ft_lstadd_back(&node1, node4);
	t_list *last_node = ft_lstlast(node1);
	printf("%d\n", *(int *)last_node->content);
}  */