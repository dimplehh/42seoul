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

void	sort(t_deque *pdeqa, t_deque *pdeqb)
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
		pdeqa->head->index <= num + 23)
		{
			pb(pdeqa, pdeqb);
			rb(pdeqb);
			num++;
		}
		else if (num + 23 < pdeqa->head->index)
			ra(pdeqa);
	}
}

int	in_sort2(int i, int cnt, t_deque *pdeqa, t_deque *pdeqb)
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

void	sort2(int cnt, t_deque *pdeqa, t_deque *pdeqb)
{
	int		i;
	t_node	*cur;

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

int	remove_all(int size, t_deque *pdeqa, t_deque *pdeqb)
{
	while (size--)
	{
		dq_remove_first(pdeqa);
		dq_remove_first(pdeqb);
	}
	return (0);
}

int	test(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;
	int		size;

	deque_init(&a);
	deque_init(&b);
	if (argc == 1)
		return (0);
	if (!check(argc, argv, &a))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	size = dq_size(&a);
	if (size == 1 || check2(&a))
		return (remove_all(size, &a, &b));
	if (dq_size(&a) <= 5)
		sort_small(&a, &b);
	else
	{
		sort(&a, &b);
		sort2(size, &a, &b);
	}
	return (remove_all(size, &a, &b));
}

int main(int argc, char **argv)
{
	test(argc, argv);
	system("leaks push_swap");
	return (0);
}
