/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:24:22 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/05/21 16:26:04 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *curr;
	t_list *temp;

	if (lst == 0 || f == 0)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	curr = new;
	lst = lst->next;
	while (lst)
	{
		if (!(temp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		curr->next = temp;
		curr = temp;
		lst = lst->next;
	}
	return (new);
}
