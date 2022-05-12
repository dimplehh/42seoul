/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:55:17 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/27 11:55:18 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_deque *pdeqa)
{
	t_node	*temp;

	if (pdeqa->head && pdeqa->head->next)
	{
		temp = pdeqa->head;
		pdeqa->head = pdeqa->head->next;
		temp->next = NULL;
		pdeqa->tail->next = temp;
		temp->prev = pdeqa->tail;
		pdeqa->tail = pdeqa->tail->next;
	}
	ft_putendl_fd("ra", 1);
}

void	rb(t_deque *pdeqb)
{
	t_node	*temp;

	if (pdeqb->head && pdeqb->head->next)
	{
		temp = pdeqb->head;
		pdeqb->head = pdeqb->head->next;
		temp->next = NULL;
		pdeqb->tail->next = temp;
		temp->prev = pdeqb->tail;
		pdeqb->tail = pdeqb->tail->next;
	}
	ft_putendl_fd("rb", 1);
}

void	rra(t_deque *pdeqa)
{
	t_node	*temp;

	temp = pdeqa->tail;
	if (pdeqa->head && pdeqa->head->next)
	{
		pdeqa->tail = pdeqa->tail->prev;
		pdeqa->tail->next = NULL;
		temp->prev = NULL;
		temp->next = pdeqa->head;
		pdeqa->head->prev = temp;
		pdeqa->head = pdeqa->head->prev;
	}
	ft_putendl_fd("rra", 1);
}

void	rrb(t_deque *pdeqb)
{
	t_node	*temp;

	temp = pdeqb->tail;
	if (pdeqb->head && pdeqb->head->next)
	{
		pdeqb->tail = pdeqb->tail->prev;
		pdeqb->tail->next = NULL;
		temp->prev = NULL;
		temp->next = pdeqb->head;
		pdeqb->head->prev = temp;
		pdeqb->head = pdeqb->head->prev;
	}
	ft_putendl_fd("rrb", 1);
}
