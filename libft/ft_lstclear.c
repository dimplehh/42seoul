/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:20:37 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/05/21 16:22:26 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *head;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		head = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = head;
	}
	*lst = 0;
}
