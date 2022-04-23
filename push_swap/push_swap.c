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

int	countList(Node *head, Node *tail)
{
	int i;

	i = 1;
	while (head != tail)
	{
		i++;
		head = head->next;
	}
	return (i);
}

Node *parition(Node *first, Node *last)
{
	struct Node *pivot = first;
	struct Node *front = first;
	int temp = 0;
	while (front != NULL && front != last)
	{
		if (front->data < last->data)
		{
			pivot = first;
			temp = first->data;
			first->data = front->data;
			front->data = temp;
			first = first->next;
		}
		front = front->next;
	}
	temp = first->data;
	first->data = last->data;
	last->data = temp;
	return (pivot);
}

void	sortTwo(struct Node *first)
{
	int temp = 0;
	if (first->data > first->next->data)
		//sa(first);
	return ;
}

void sortThree(struct Node *first, struct Node *last)
{
    int temp = 0;
    int temp2 = 0;
    if(first->data < last->data && first->next->data > last->data)
    {
        temp = first->next->data;
        first->next->data = last->data;
        last->data = temp;
    }
    if(first->data < last->data && first->next->data < first->data)
        //sa(first);
    if(first->data > first->next->data && first->next->data > last->data)
    {
        temp = first->data;
        first->data = last->data;
        last->data = temp;
    }
    if(first->data > last->data && first->next->data > first->data)
    {
        temp = last->data;
        temp2 = first->data;
        last->data = first->next->data;
        first->data = temp;
        first->next->data = temp2;
    }
    if(first->data > last->data && last->data > first->next->data)
    {
        temp = first->next->data;
        temp2 = last->data;
        last->data = first->data;
        first->data = temp;
        first->next->data = temp2;
    }
    return ;
}

void quick_sort(struct Node *first, struct Node *last)
{
	if (first == last)
		return;
    if (countList(first, last) == 2)
        return (sortTwo(first));
    if (countList(first, last) == 3)
        return (sortThree(first, last));
	struct Node *pivot = parition(first, last);
	if (pivot != NULL && pivot->next != NULL)
		quick_sort(pivot->next, last);
	if (pivot != NULL && first != pivot)
		quick_sort(first, pivot);
}

int main(int argc, char **argv)
{
    Deque a;
    Deque b;
    DequeInit(&a);
    DequeInit(&b);
    int i;

    i = 1;
    while(i < argc)//에러처리에러치리, 중복검사
    {
        if(!(-2147483647 <= ft_atoi(argv[i]) && ft_atoi(argv[i]) <= 2147483647) || ft_atoi(argv[i]) == 0)
        {
            printf("error\n");
            return (0);
        }
        i++;
    }
    i = 1;
    while(i < argc)
        DQAddLast(&a, atoi(argv[i++]));
    i = 1;
    while(i < argc)
        DQAddLast(&b, atoi(argv[i++]));
    show(&a);
    rrr(&a, &b);
    //quick_sort(a.head, a.tail);
    show(&a);
    show(&b);
    return (0);
}
