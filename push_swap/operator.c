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

void sa(Deque *pdeq)//차후에 데이터, 인덱스 둘 다 바뀌도록 설정
{
	int temp;
	if (pdeq->head && pdeq->head->next)
	{
		temp = pdeq->head->index;
		pdeq->head->index = pdeq->head->next->index;
		pdeq->head->next->index = temp;
		printf("sa\n");
	}
}

void sb(Deque *pdeq)
{
	int temp;
	if (pdeq->head && pdeq->head->next)
	{
		temp = pdeq->head->index;
		pdeq->head->index = pdeq->head->next->index;
		pdeq->head->next->index = temp;
		printf("sb\n");
	}
}

void ss(Deque *pdeqa, Deque *pdeqb)
{
	int temp = 0;
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

void pa(Deque *pdeqa, Deque *pdeqb)
{
	if(!pdeqb->head)
		return;
	Node *newHead = pdeqb->head;
	if (pdeqb->head->next && newHead != pdeqb->tail)
		pdeqb->head = pdeqb->head->next;
	else
	{
		pdeqb->head = NULL;
		free(pdeqb->head);
	}
	if (pdeqa->head == NULL)
	{
		DQAddLast(pdeqa, newHead->index);
		pdeqa->head->index = newHead->index;
	}
	else
	{
		newHead->next = pdeqa->head;
		pdeqa->head->prev = newHead;
		pdeqa->head = newHead;
	}
	printf("pa\n");
}

void pb(Deque *pdeqa, Deque *pdeqb)
{
	if(!pdeqa->head)
		return;
	Node *newHead = pdeqa->head;
	if (pdeqa->head->next)
		pdeqa->head = pdeqa->head->next;
	else
		pdeqa->head = NULL;
	if (pdeqb->head == NULL)
	{
		DQAddLast(pdeqb, newHead->index);
		pdeqb->head->index = newHead->index;
	}
	else
	{
		newHead->next = pdeqb->head;
		pdeqb->head->prev = newHead;
		pdeqb->head = newHead;
	}
	printf("pb\n");
}

void ra(Deque *pdeqa)
{
	if (pdeqa->head && pdeqa->head->next)
	{
		Node *temp = pdeqa->head;
		pdeqa->head = pdeqa->head->next;
		pdeqa->tail->next = temp;
		temp->prev = pdeqa->tail;
		pdeqa->tail = pdeqa->tail->next;
	}
	printf("ra\n");
}

void rb(Deque *pdeqb)
{
	if (pdeqb->head && pdeqb->head->next)
	{
		Node *temp = pdeqb->head;
		pdeqb->head = pdeqb->head->next;
		pdeqb->tail->next = temp;
		temp->prev = pdeqb->tail;
		pdeqb->tail = pdeqb->tail->next;
	}
	printf("rb\n");
}

void rr(Deque *pdeqa, Deque *pdeqb)
{
	if (pdeqa->head)
	{
		Node *temp1 = pdeqa->head;
		pdeqa->head = pdeqa->head->next;
		pdeqa->tail->next = temp1;
		temp1->prev = pdeqa->tail;
		pdeqa->tail = pdeqa->tail->next;
	}
	if (pdeqb->head)
	{
		Node *temp2 = pdeqb->head;
		pdeqb->head = pdeqb->head->next;
		pdeqb->tail->next = temp2;
		temp2->prev = pdeqb->tail;
		pdeqb->tail = pdeqb->tail->next;   
	}
	printf("rr\n");
}

void rra(Deque *pdeqa)
{
	if(pdeqa->head == NULL)
		return ;
	Node *temp = pdeqa->head;
	Node *temp2 = pdeqa->tail;
	pdeqa->tail = pdeqa->tail->prev;
	pdeqa->head = temp2;
	pdeqa->head->next = temp;
	temp->prev = pdeqa->head;
	printf("rra\n");
}

void rrb(Deque *pdeqb)
{
	if(pdeqb->head == NULL)
		return ;
	Node *temp = pdeqb->head;
	Node *temp2 = pdeqb->tail;
	pdeqb->tail = pdeqb->tail->prev;
	pdeqb->head = temp2;
	pdeqb->head->next = temp;
	temp->prev = pdeqb->head;
	printf("rrb\n");
}

void rrr(Deque *pdeqa, Deque *pdeqb)
{
	if (pdeqa->head)
	{
		Node *temp = pdeqa->head;
		Node *temp2 = pdeqa->tail;
		pdeqa->tail = pdeqa->tail->prev;
		pdeqa->head = temp2;
		pdeqa->head->next = temp;
		temp->prev = pdeqa->head;
	}
	if (pdeqb->head)
	{
		Node *temp3 = pdeqb->head;
		Node *temp4 = pdeqb->tail;
		pdeqb->tail = pdeqb->tail->prev;
		pdeqb->head = temp4;
		pdeqb->head->next = temp3;
		temp3->prev = pdeqb->head;
	}
	printf("rrr\n");
}