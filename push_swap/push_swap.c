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

void	sort(int count, Deque *pdeqa, Deque *pdeqb)
{
	int	num;
	int	i;

	num = 0;
	i = 1;
	while (i < count && pdeqa->head)
	{
		if (pdeqa->head->index <= num)
		{
			pb(pdeqa, pdeqb);
			num++;
		}
		if (pdeqa->head && num < pdeqa->head->index && \
		pdeqa->head->index <= num + CHUNK)
		{
			pb(pdeqa, pdeqb);
			rb(pdeqb);
			num++;
		}
		if (pdeqa->head && num + CHUNK < pdeqa->head->index)
			ra(pdeqa);
		i++;
	}
}

void	sort2(int cnt, Deque *pdeqa, Deque *pdeqb)
{
	int		max;
	int		i;
	Node	*cur;

	while (cnt > 1)
	{
		cur = pdeqb->head;
		i = 0;
		max = cnt - 1;
		while (cur != NULL)
		{
			if (cur->index == max)
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
	Deque	a;
	Deque	b;
	int		i;

	DequeInit(&a);
	DequeInit(&b);
	if (!check(argc, argv))
		return (0);
	i = 1;
	while (i < argc)
		DQAddLast(&a, atoi(argv[i++]));
	show(&a);
	if (DQsize(&a) <= 5)
		sort_small(&a, &b);
	else
	{
		sort(argc, &a, &b);
		sort2(argc - 1, &a, &b);
	}
	show(&a);
	return (0);
}
