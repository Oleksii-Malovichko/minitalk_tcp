/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:35:17 by alex              #+#    #+#             */
/*   Updated: 2024/10/12 14:39:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* t_list *ft_lstnew(void *content)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

void print_content(void *content)
{
    printf("%d\n", *(int *)content);
}

int main() {
    t_list *list = NULL;


    for (int i = 1; i <= 3; i++) {
        int *value = malloc(sizeof(int));
        *value = i;
        t_list *new_node = ft_lstnew(value);
        new_node->next = list;
        list = new_node;
    }
    ft_lstiter(list, print_content);
} */