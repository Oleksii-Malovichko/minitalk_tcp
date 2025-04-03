/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:20:57 by alex              #+#    #+#             */
/*   Updated: 2024/10/12 14:33:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		del(current->content);
		free(current);
	}
	*lst = NULL;
}

/* t_list *ft_lstnew(void *content)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

void del_content(void *content)
{
    free(content);
}

int main()
{
	t_list *list = NULL;

    for (int i = 1; i <= 3; i++) {
        int *value = malloc(sizeof(int));
        *value = i;
        t_list *new_node = ft_lstnew(value);
        new_node->next = list;
        list = new_node;
    }

    // Удаляем весь список
    ft_lstclear(&list, del_content); // Передаем адрес указателя на список

    // Проверяем, что список теперь пуст
    if (!list) {
        printf("List successfully cleared.\n");
    } else {
        printf("List still exists.\n");
    }
} */