/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:22:10 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/21 14:22:11 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_Deque *pdeq)
{
	int	temp;
	int	tempd;

	if (pdeq->head && pdeq->head->next)
	{
		temp = pdeq->head->index;
		tempd = pdeq->head->data;
		pdeq->head->index = pdeq->head->next->index;
		pdeq->head->data = pdeq->head->next->data;
		pdeq->head->next->index = temp;
		pdeq->head->next->data = tempd;
		ft_putendl_fd("sa", 1);
	}
}

void	sb(t_Deque *pdeq)
{
	int	temp;
	int	tempd;

	if (pdeq->head && pdeq->head->next)
	{
		temp = pdeq->head->index;
		tempd = pdeq->head->data;
		pdeq->head->index = pdeq->head->next->index;
		pdeq->head->data = pdeq->head->next->data;
		pdeq->head->next->index = temp;
		pdeq->head->next->data = tempd;
		ft_putendl_fd("sb", 1);
	}
}

void	pa(t_Deque *pdeqa, t_Deque *pdeqb)
{
	int		temp_idx;
	t_Node	*newhead;

	if (!pdeqb->head)
		return ;
	newhead = pdeqb->head;
	temp_idx = dq_remove_first(pdeqb);
	dq_add_first(pdeqa, temp_idx);
	ft_putendl_fd("pa", 1);
}

void	pb(t_Deque *pdeqa, t_Deque *pdeqb)
{
	int		temp_idx;
	t_Node	*newhead;

	if (!pdeqa->head)
		return ;
	newhead = pdeqa->head;
	temp_idx = dq_remove_first(pdeqa);
	dq_add_first(pdeqb, temp_idx);
	ft_putendl_fd("pb", 1);
}
