/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortSmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:55:01 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/25 17:55:01 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_sort(t_deque *pdeq)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = pdeq->head;
	while (cur != pdeq->tail)
	{
		if (cur->index > cur->next->index)
			if (cur != pdeq->tail)
				return (0);
		cur = cur->next;
	}
	return (1);
}

void	sort_three(t_deque *a)
{
	if (a->head->index < a->tail->index && \
	a->head->next->index > a->tail->index)
	{
		sa(a);
		ra(a);
	}
	else if (a->head->index < a->tail->index && \
	a->head->next->index < a->head->index)
		sa(a);
	else if (a->head->index > a->head->next->index && \
	a->head->next->index > a->tail->index)
	{
		ra(a);
		sa(a);
	}
	else if (a->head->index > a->tail->index && \
	a->head->next->index > a->head->index)
		rra(a);
	else if (a->head->index > a->tail->index && \
	a->tail->index > a->head->next->index)
		ra(a);
}

void	sort_idx(t_deque *a, int idx)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = a->head;
	while (cur != NULL)
	{
		if (cur->index == idx)
		{
			if (i > dq_size(a) / 2)
				while (dq_size(a) - i++ > 0)
					rra(a);
			else
				while (i-- > 0)
					ra(a);
			break ;
		}
		cur = cur->next;
		i++;
	}
}

void	sort_five(t_deque *a, t_deque *b)
{
	sort_idx(a, 0);
	pb(a, b);
	sort_idx(a, 1);
	pb(a, b);
	if (!is_sort(a))
		sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_small(t_deque *pdeqa, t_deque *pdeqb)
{
	if (dq_size(pdeqa) == 2)
		if (pdeqa->head->index > pdeqa->head->next->index)
			sa(pdeqa);
	if (dq_size(pdeqa) == 3)
		sort_three(pdeqa);
	if (dq_size(pdeqa) == 4)
	{
		sort_idx(pdeqa, 0);
		if (!is_sort(pdeqa))
		{
			pb(pdeqa, pdeqb);
			sort_three(pdeqa);
			pa(pdeqa, pdeqb);
		}
	}
	if (dq_size(pdeqa) == 5)
		sort_five(pdeqa, pdeqb);
}
