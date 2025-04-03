/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:19:33 by alex              #+#    #+#             */
/*   Updated: 2024/10/16 12:20:05 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	del_content(void *content)
{
	free(content);
}

/* 
int main() {
    int *value = malloc(sizeof(int));
    *value = 42;
    t_list *node = ft_lstnew(value);

    printf("Value before deletion: %d\n", *(int *)node->content);

    ft_lstdelone(node, del_content);

    if (!node) {
        printf("Node successfully deleted.\n");
    } else {
        printf("Node still exists.\n");
    }
} */