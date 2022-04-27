/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:43:31 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/23 13:38:38 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	chunk(int x)
{
	return (0.000000053 * x * x + 0.03 * x + 14.5);
}

void	sort(int count, t_Deque *pdeqa, t_Deque *pdeqb)
{
	int	num;

	num = 0;
	while (pdeqa->head)
	{
		if (pdeqa->head->index <= num)
		{
			pb(pdeqa, pdeqb);
			num++;
		}
		else if (num < pdeqa->head->index && \
		pdeqa->head->index <= num + chunk(count))
		{
			pb(pdeqa, pdeqb);
			rb(pdeqb);
			num++;
		}
		else if (num + chunk(count) < pdeqa->head->index)
			ra(pdeqa);
	}
}

int	in_sort2(int i, int cnt, t_Deque *pdeqa, t_Deque *pdeqb)
{
	if (i > cnt / 2)
	{
		while (cnt - i++ > 0)
			rrb(pdeqb);
		pa(pdeqa, pdeqb);
	}
	else
	{
		while (i-- > 0)
			rb(pdeqb);
		pa(pdeqa, pdeqb);
	}
	return (i);
}

void	sort2(int cnt, t_Deque *pdeqa, t_Deque *pdeqb)
{
	int		i;
	t_Node	*cur;

	while (cnt > 1)
	{
		cur = pdeqb->head;
		i = 0;
		while (cur != NULL)
		{
			if (cur->index == cnt - 1)
			{
				i = in_sort2(i, cnt, pdeqa, pdeqb);
				break ;
			}
			cur = cur->next;
			i++;
		}
		cnt--;
	}
	pa(pdeqa, pdeqb);
}

int	main(int argc, char **argv)
{
	t_Deque	a;
	t_Deque	b;
	int		size;

	deque_init(&a);
	deque_init(&b);
	if (!check(argc, argv, &a))
	{
		ft_putendl_fd("ERROR", 1);
		return (0);
	}
	size = dq_size(&a);
	if (check2(&a))
		return (0);
	if (dq_size(&a) <= 5)
		sort_small(&a, &b);
	else
	{
		sort(size, &a, &b);
		sort2(size, &a, &b);
	}
	return (0);
}
