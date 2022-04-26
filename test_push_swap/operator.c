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
		printf("sa\n");
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
		printf("sb\n");
	}
}

void	ss(t_Deque *pdeqa, t_Deque *pdeqb)
{
	int	temp;

	if (pdeqa->head && pdeqa->head->next)
	{
		temp = pdeqa->head->index;
		pdeqa->head->index = pdeqa->head->next->index;
		pdeqa->head->next->index = temp;
	}
	if (pdeqb->head && pdeqb->head->next)
	{
		temp = pdeqb->head->index;
		pdeqb->head->index = pdeqb->head->next->index;
		pdeqb->head->next->index = temp;
	}
	printf("ss\n");
}

void	pa(t_Deque *pdeqa, t_Deque *pdeqb)
{
	t_Node	*target;

	target = pdeqb->head;
	if (pdeqb->head == pdeqb->tail)
		printf("$$$$$$$$$$$\n");
	if (target == NULL)
		return ;
	if (target->next)
		(target->next)->prev = NULL;
	pdeqb->head = target->next;
	if (!target->next)
		printf("wtf???\n");
	if (!pdeqb->head)
		printf("home...please\n");
	if (!target->next && !pdeqb->head)
		printf("AAAAAAAAAAA\n");
	target->next = pdeqa->head;
	if (pdeqa->head == NULL)
		DQAddFirst(pdeqa, target->index);
	else
	{
		(pdeqa->head)->prev = target;
		pdeqa->head = target;
	}
	printf("pa\n");
	printf("head [%d], tail [%d]\n", pdeqb->head->index, pdeqb->tail->index);
}

void	pb(t_Deque *pdeqa, t_Deque *pdeqb)
{
	t_Node	*target;

	target = pdeqa->head;
	if (target == NULL)
		return ;
	if (target->next)
		(target->next)->prev = NULL;
	pdeqa->head = target->next;
	if (!target->next)
		printf(">>wtf???\n");
	if (!pdeqa->head)
		printf(">>home...please\n");
	if (!target->next && !pdeqa->head)
		printf(">>AAAAAAAAAAA\n");
	target->next = pdeqb->head;
	if (pdeqb->head == NULL)
		DQAddFirst(pdeqb, target->index);
	else
	{
		(pdeqb->head)->prev = target;
		pdeqb->head = target;
	}
	printf("pb\n");
}

void ra(t_Deque *pdeqa)
{
	if (pdeqa->head && pdeqa->head->next)
	{
		t_Node *temp = pdeqa->head;
		pdeqa->head = pdeqa->head->next;
		pdeqa->tail->next = temp;
		temp->prev = pdeqa->tail;
		pdeqa->tail = pdeqa->tail->next;
	}
	printf("ra\n");
}

void rb(t_Deque *pdeqb)
{
	if (pdeqb->head && pdeqb->head->next)
	{
		t_Node *temp = pdeqb->head;
		pdeqb->head = pdeqb->head->next;
		pdeqb->tail->next = temp;
		temp->prev = pdeqb->tail;
		pdeqb->tail = pdeqb->tail->next;
	}
	printf("rb\n");
}

void rr(t_Deque *pdeqa, t_Deque *pdeqb)
{
	if (pdeqa->head)
	{
		t_Node *temp1 = pdeqa->head;
		pdeqa->head = pdeqa->head->next;
		pdeqa->tail->next = temp1;
		temp1->prev = pdeqa->tail;
		pdeqa->tail = pdeqa->tail->next;
	}
	if (pdeqb->head)
	{
		t_Node *temp2 = pdeqb->head;
		pdeqb->head = pdeqb->head->next;
		pdeqb->tail->next = temp2;
		temp2->prev = pdeqb->tail;
		pdeqb->tail = pdeqb->tail->next;   
	}
	printf("rr\n");
}

void rra(t_Deque *pdeqa)
{
	if(pdeqa->head == NULL)
		return ;
	t_Node *temp = pdeqa->head;
	t_Node *temp2 = pdeqa->tail;
	pdeqa->tail = pdeqa->tail->prev;
	pdeqa->head = temp2;
	pdeqa->head->next = temp;
	temp->prev = pdeqa->head;
	printf("rra\n");
}

void rrb(t_Deque *pdeqb)
{
	if(pdeqb->head == NULL)
		return ;
	t_Node *temp = pdeqb->head;
	t_Node *temp2 = pdeqb->tail;
	pdeqb->tail = pdeqb->tail->prev;
	pdeqb->head = temp2;
	pdeqb->head->next = temp;
	temp->prev = pdeqb->head;
	printf("rrb\n");
}

void rrr(t_Deque *pdeqa, t_Deque *pdeqb)
{
	if (pdeqa->head)
	{
		t_Node *temp = pdeqa->head;
		t_Node *temp2 = pdeqa->tail;
		pdeqa->tail = pdeqa->tail->prev;
		pdeqa->head = temp2;
		pdeqa->head->next = temp;
		temp->prev = pdeqa->head;
	}
	if (pdeqb->head)
	{
		t_Node *temp3 = pdeqb->head;
		t_Node *temp4 = pdeqb->tail;
		pdeqb->tail = pdeqb->tail->prev;
		pdeqb->head = temp4;
		pdeqb->head->next = temp3;
		temp3->prev = pdeqb->head;
	}
	printf("rrr\n");
}