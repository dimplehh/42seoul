/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:43:31 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/12/07 17:04:54 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void pa()
{
    swap(&head->next->data, &head->next->next->data);
}

int main(void) {
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    insert(2);
    insert(1);
    insert(3);
    insert(9);
    insert(7);
    //tail->prev = head->next->next->next;
    tail->next = head;
    head->prev = tail;
    tail->prev->next = tail->next->next;
    head->next = head->next->next;
    //ra();
    show();
    return 0;
}