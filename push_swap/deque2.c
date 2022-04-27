/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:02:55 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/27 12:02:56 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	deque_init(t_Deque	*pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int	dq_is_empty(t_Deque	*pdeq)
{
	if (pdeq->head == NULL)
		return (1);
	else
		return (0);
}

int	dq_size(t_Deque	*pdeq)
{
	int		i;
	t_Node	*cur;

	i = 0;
	cur = pdeq->head;
	if (!dq_is_empty(pdeq))
	{
		while (cur != pdeq->tail)
		{
			cur = cur->next;
			i++;
		}
		return (i + 1);
	}
	return (0);
}
