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

void sa(Deque *pdeq)
{
    int temp = 0;
    temp = pdeq->head->data;
    pdeq->head->data = pdeq->head->next->data;
    pdeq->head->next->data = temp;
    printf("sa\n");
}

void sb(Deque *pdeq)
{
    int temp = 0;
    temp = pdeq->head->data;
    pdeq->head->data = pdeq->head->next->data;
    pdeq->head->next->data = temp;
    printf("sa\n");
}

void ss(Deque *pdeqa, Deque *pdeqb)
{
    int temp = 0;
    temp = pdeqa->head->data;
    pdeqa->head->data = pdeqa->head->next->data;
    pdeqa->head->next->data = temp;
    temp = pdeqb->head->data;
    pdeqb->head->data = pdeqb->head->next->data;
    pdeqb->head->next->data = temp;
    printf("ss\n");
}

void pa(Deque *pdeqa, Deque *pdeqb)
{
    if(pdeqb->head == NULL)
        return ;
    Node *newHead = pdeqb->head;
    pdeqb->head = pdeqb->head->next;
    newHead->next = pdeqa->head;
    pdeqa->head = newHead;
    printf("pa\n");
}

void pb(Deque *pdeqa, Deque *pdeqb)
{
    if(pdeqa->head == NULL)
        return ;
    Node *newHead = pdeqa->head;
    pdeqa->head = pdeqa->head->next;
    newHead->next = pdeqb->head;
    pdeqb->head = newHead;
    printf("pb\n");
}

void ra(Deque *pdeqa)
{
    Node *temp = pdeqa->head;
    pdeqa->head = pdeqa->head->next;
    pdeqa->tail->next = temp;
    pdeqa->tail = pdeqa->tail->next;
    printf("ra\n");
}

void rb(Deque *pdeqb)
{
    Node *temp = pdeqb->head;
    pdeqb->head = pdeqb->head->next;
    pdeqb->tail->next = temp;
    pdeqb->tail = pdeqb->tail->next;
    printf("rb\n");
}

void rr(Deque *pdeqa, Deque *pdeqb)
{
    Node *temp1 = pdeqa->head;
    pdeqa->head = pdeqa->head->next;
    pdeqa->tail->next = temp1;
    pdeqa->tail = pdeqa->tail->next;
    Node *temp2 = pdeqb->head;
    pdeqb->head = pdeqb->head->next;
    pdeqb->tail->next = temp2;
    pdeqb->tail = pdeqb->tail->next;
    printf("rr\n");
}

void rra(Deque *pdeqa)
{
    Node *temp = pdeqa->head;
    Node *temp2 = pdeqa->tail;
    pdeqa->tail = pdeqa->tail->prev;
    pdeqa->head = temp2;
    pdeqa->head->next = temp;
    printf("rra\n");
}

void rrb(Deque *pdeqb)
{
    Node *temp = pdeqb->head;
    Node *temp2 = pdeqb->tail;
    pdeqb->tail = pdeqb->tail->prev;
    pdeqb->head = temp2;
    pdeqb->head->next = temp;
    printf("rrb\n");
}

void rrr(Deque *pdeqa, Deque *pdeqb)
{
    Node *temp = pdeqa->head;
    Node *temp2 = pdeqa->tail;
    pdeqa->tail = pdeqa->tail->prev;
    pdeqa->head = temp2;
    pdeqa->head->next = temp;
    Node *temp3 = pdeqb->head;
    Node *temp4 = pdeqb->tail;
    pdeqb->tail = pdeqb->tail->prev;
    pdeqb->head = temp4;
    pdeqb->head->next = temp3;
    printf("rrr\n");
}