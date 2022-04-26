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

int	is_sort(t_Deque *pdeq)
{
	int		i;
	t_Node	*cur;

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

void	sort_three(t_Deque *a, t_Deque *b)
{
	int	temp;
	int	temp2;

	if (a->head->index < a->tail->index && a->head->next->index > a->tail->index)
	{
		pb(a, b);
		sa(a);
		pa(a, b);
	}
	if (a->head->index < a->tail->index && a->head->next->index < a->head->index)
		sa(a);
	if (a->head->index > a->head->next->index && a->head->next->index > a->tail->index)
	{
		ra(a);
		sa(a);
	}
	if (a->head->index > a->tail->index && a->head->next->index > a->head->index)
		rra(a);
	if (a->head->index > a->tail->index && a->tail->index > a->head->next->index)
		ra(a);
}

void	sort_idx(t_Deque *a, t_Deque *b, int idx)
{
	int		i;
	t_Node	*cur;

	i = 0;
	cur = a->head;
	while (cur != NULL)
	{
		if (cur->index == idx)
		{
			if (i > DQsize(a) / 2)
				while (DQsize(a) - i++ > 0)
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

void	sort_five(t_Deque *a, t_Deque *b)
{
	sort_idx(a, b, 0);
	pb(a, b);
	sort_idx(a, b, 1);
	pb(a, b);
	if (!is_sort(a))
		sort_three(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_small(t_Deque *pdeqa, t_Deque *pdeqb)
{
	if (DQsize(pdeqa) == 2)
		if (pdeqa->head->index > pdeqa->head->next->index)
			sa(pdeqa);
	if (DQsize(pdeqa) == 3)
		sort_three(pdeqa, pdeqb);
	if (DQsize(pdeqa) == 4)
	{
		sort_idx(pdeqa, pdeqb, 0);
		if (!is_sort(pdeqa))
		{
			pb(pdeqa, pdeqb);
			sort_three(pdeqa, pdeqb);
			pa(pdeqa, pdeqb);
		}
	}
	if (DQsize(pdeqa) == 5)
		sort_five(pdeqa, pdeqb);
}