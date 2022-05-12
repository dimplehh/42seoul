/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:35:43 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/27 13:35:45 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_duple(t_deque *pdeq)
{
	t_node	*cur;
	t_node	*newhead;

	newhead = pdeq->head;
	if (newhead->next)
		cur = newhead->next;
	while (newhead)
	{
		while (cur)
		{
			if (newhead->data == cur->data)
				return (1);
			cur = cur->next;
		}
		newhead = newhead->next;
		if (newhead && newhead->next)
			cur = newhead->next;
	}
	return (0);
}

int	is_sorting(t_deque *pdeq)
{
	t_node	*cur;
	t_node	*newhead;

	newhead = pdeq->head;
	if (newhead->next)
		cur = newhead->next;
	while (newhead)
	{
		while (cur)
		{
			if (newhead->data >= cur->data)
				return (0);
			cur = cur->next;
		}
		newhead = newhead->next;
		if (newhead && newhead->next)
			cur = newhead->next;
	}
	return (1);
}

int	check2(t_deque *pdeq)
{
	if (is_duple(pdeq))
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	else if (is_sorting(pdeq))
		return (1);
	return (0);
}
