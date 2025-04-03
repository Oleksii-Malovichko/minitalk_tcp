/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:40:34 by alex              #+#    #+#             */
/*   Updated: 2024/10/21 16:17:19 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;

	new_list = NULL;
	current = NULL;
	while (lst)
	{
		if (!process_node(&new_list, &current, f(lst->content), del))
			return (NULL);
		lst = lst->next;
	}
	return (new_list);
}

int	process_node(t_list **new_list, t_list **current,
		void *new_content, void (*del)(void *))
{
	t_list	*new_node;

	if (!new_content)
	{
		ft_lstclear(new_list, del);
		return (0);
	}
	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		del(new_content);
		ft_lstclear(new_list, del);
		return (0);
	}
	if (!*new_list)
		*new_list = new_node;
	else
		(*current)->next = new_node;
	*current = new_node;
	return (1);
}

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*current;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		current = *lst;
// 		*lst = (*lst)->next;
// 		del(current->content);
// 		free(current);
// 	}
// 	*lst = NULL;
// }

// t_list *ft_lstnew(void *content)
// {
//     t_list *new_node = malloc(sizeof(t_list));
//     if (!new_node) return NULL;
//     new_node->content = content;
//     new_node->next = NULL;
//     return new_node;
// }

// void *double_value(void *content)
// {
//     int *new_value = malloc(sizeof(int));
//     if (!new_value) return NULL;
//     *new_value = (*(int *)content) * 2;
//     return new_value;
// }

// void del_content(void *content)
// {
//     free(content);
// }

// int main()
// {
//     t_list *list = NULL;

//     for (int i = 1; i <= 3; i++) {
//         int *value = malloc(sizeof(int));
//         *value = i;
//         t_list *new_node = ft_lstnew(value);
//         new_node->next = list;
//         list = new_node;
//     }

//     t_list *new_list = ft_lstmap(list, double_value, del_content);

//     t_list *current = new_list;
//     while (current) {
//         printf("%d\n", *(int *)current->content);
//         current = current->next;
//     }
// }