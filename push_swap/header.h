/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:41:21 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/03/12 13:41:26 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    int index;
    struct Node *next;
}Node;

typedef struct Deque
{
    Node* head;
    Node* tail;
}Deque;

void insert(int data);
void removeFront();
void show();
int	ft_atoi(const char *str);
void sa(Deque *pdeq);
void sb(Deque *pdeq);
void ss(Deque *pdeqa, Deque *pdeqb);
void pa(Deque *pdeqa, Deque *pdeqb);
void pb(Deque *pdeqa, Deque *pdeqb);
void ra(Deque *pdeqa);
void rb(Deque *pdeqb);
void rr(Deque *pdeqa, Deque *pdeqb);
void rra(Deque *pdeqa);
void rrb(Deque *pdeqb);
void rrr(Deque *pdeqa, Deque *pdeqb);
void show(Deque* pdeq);
int DQsize(Deque* pdeq);
void DQAddLast(Deque* pdeq, int data);
int DQIsEmpty(Deque* pdeq);
void DequeInit(Deque* pdeq);

#endif
