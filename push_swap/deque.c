/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:49:32 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/27 11:49:33 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dq_indexing(t_Deque	*pdeq)
{
	t_Node	*cur;

	cur = pdeq->head;
	if (dq_is_empty(pdeq))
		pdeq->head->index = 0;
	else
	{
		while (cur != pdeq->tail)
		{
			if (cur->data < pdeq->tail->data)
				pdeq->tail->index++;
			else
				cur->index++;
			cur = cur->next;
		}
	}
}

int	dq_remove_first(t_Deque	*pdeq)
{
	t_Node	*newnode;
	int		index;

	newnode = pdeq->head;
	index = pdeq->head->index;
	pdeq->head = pdeq->head->next;
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;
	free(newnode);
	return (index);
}

void	dq_add_last(t_Deque	*pdeq, int data)
{
	t_Node	*newnode;

	newnode = (t_Node *)malloc(sizeof(t_Node));
	if (!newnode)
		exit(1);
	newnode->data = data;
	newnode->index = 0;
	newnode->prev = pdeq->tail;
	if (dq_is_empty(pdeq))
		pdeq->head = newnode;
	else
		pdeq->tail->next = newnode;
	newnode->next = NULL;
	pdeq->tail = newnode;
	dq_indexing(pdeq);
}

void	dq_add_first(t_Deque	*pdeq, int index)
{
	t_Node	*newnode;

	newnode = (t_Node *)malloc(sizeof(t_Node));
	if (!newnode)
		exit(1);
	newnode->index = index;
	newnode->next = pdeq->head;
	if (dq_is_empty(pdeq))
		pdeq->tail = newnode;
	else
		pdeq->head->prev = newnode;
	newnode->prev = NULL;
	pdeq->head = newnode;
}
