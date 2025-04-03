/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:26:38 by alex              #+#    #+#             */
/*   Updated: 2024/10/12 11:39:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int main()
{
	int *value = malloc(sizeof(int));

	*value = 42;
	t_list *node = ft_lstnew(value);
	if (node)
	{
		printf("Content: %d\n", *(int *)node->content);
	}
	else
	{
		printf("Failed to create node\n");
	}
} */