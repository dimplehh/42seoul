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
    if (pdeq->head && pdeq->head->next)
    {
        int temp = 0;//지금은 인덱스값만 바뀌지만 data까지 바뀌도록 차후 수정
        temp = pdeq->head->index;
        pdeq->head->index = pdeq->head->next->index;
        pdeq->head->next->index = temp;
        printf("sa\n");
    }
}

void sb(Deque *pdeq)
{
    if (pdeq->head && pdeq->head->next)
    {
        int temp = 0;
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
    if(pdeqa->head == NULL)
        return ;
    Node *temp = pdeqa->head;
    pdeqa->head = pdeqa->head->next;
    pdeqa->tail->next = temp;
    pdeqa->tail = pdeqa->tail->next;
    printf("ra\n");
}

void rb(Deque *pdeqb)
{
    if (pdeqb->head == NULL)
        return ;
    Node *temp = pdeqb->head;
    pdeqb->head = pdeqb->head->next;
    pdeqb->tail->next = temp;
    pdeqb->tail = pdeqb->tail->next;
    printf("rb\n");
}

void rr(Deque *pdeqa, Deque *pdeqb)
{
    if (pdeqa->head)
    {
        Node *temp1 = pdeqa->head;
        pdeqa->head = pdeqa->head->next;
        pdeqa->tail->next = temp1;
        pdeqa->tail = pdeqa->tail->next;
    }
    if (pdeqb->head)
    {
        Node *temp2 = pdeqb->head;
        pdeqb->head = pdeqb->head->next;
        pdeqb->tail->next = temp2;
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
    }
    if (pdeqb->head)
    {
        Node *temp3 = pdeqb->head;
        Node *temp4 = pdeqb->tail;
        pdeqb->tail = pdeqb->tail->prev;
        pdeqb->head = temp4;
        pdeqb->head->next = temp3;
    }
    printf("rrr\n");
}