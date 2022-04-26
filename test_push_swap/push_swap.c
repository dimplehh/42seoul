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

int	calculate_chunk(int x)
{
	return (0.000000053 * x * x + 0.03 * x + 14.5);
}

void	sort(int count, t_Deque *pdeqa, t_Deque *pdeqb)
{
	int	num;
	int	i;
	int	chunk;

	num = 0;
	i = 0;
	chunk = calculate_chunk(count);
	show(pdeqa);
	while (pdeqa->head)
	{
		if (pdeqa->head->index <= num)
		{
			pb(pdeqa, pdeqb);
			num++;
		}
		else if (pdeqa->head && num < pdeqa->head->index && \
		pdeqa->head->index <= num + chunk)
		{
			pb(pdeqa, pdeqb);
			rb(pdeqb);
			num++;
		}
		else if (pdeqa->head && num + chunk < pdeqa->head->index)
			ra(pdeqa);
		i++;
	}
	show(pdeqa);
	show(pdeqb);
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
	//show(pdeqa);
	return (i);
}

void	sort2(int cnt, t_Deque *pdeqa, t_Deque *pdeqb)
{
	int		i;
	t_Node	*cur;

	while (cnt > 1)//여기 수정해야할듯
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

void show(t_Deque* pdeq)
{
	t_Node	*cur;

	if (!DQIsEmpty(pdeq))
	{
		cur = pdeq->head;
		while (cur != pdeq->tail)
		{
			printf("%d ", cur->index);
			cur = cur->next;
		}
		printf("%d ", cur->index);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_Deque	a;
	t_Deque	b;
	int		size;

	DequeInit(&a);
	DequeInit(&b);
	if (!check(argc, argv, &a))
		return (0);
	size = DQsize(&a);
	show(&a);
	if (DQsize(&a) <= 5)
		sort_small(&a, &b);
	else
	{
		sort(size, &a, &b);
		//sort2(size, &a, &b);
	}
	pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);pa(&a, &b);
	if (a.head)
		show(&a);
	if (b.head)
		//show(&b);
	return (0);
}
