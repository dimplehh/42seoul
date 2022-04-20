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

void swap ( int* a, int* b )
{ int t = *a; *a = *b; *b = t; }
struct Node *lastNode(struct Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

struct Node *last_node(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}

struct Node *parition(struct Node *first, struct Node *last)
{
	//Get first node of given linked list
	struct Node *pivot = first;
	struct Node *front = first;
	int temp = 0;
	while (front != NULL && front != last)
	{
		if (front->data < last->data)
		{
			pivot = first;
			//Swap node value
			temp = first->data;
			first->data = front->data;
			front->data = temp;
			//Visit to next node
			first = first->next;
		}
		//Visit to next node
		front = front->next;
	}
	//Change last node value to current node
	temp = first->data;
	first->data = last->data;
	last->data = temp;
	return pivot;
}
//Perform quick sort in given linked list
void quick_sort(struct Node *first, struct Node *last)
{
	if (first == last)
	{
		return;
	}
	struct Node *pivot = parition(first, last);
	if (pivot != NULL && pivot->next != NULL)
	{
		quick_sort(pivot->next, last);
	}
	if (pivot != NULL && first != pivot)
	{
		quick_sort(first, pivot);
	}
}
void printList(struct Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)
               malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node ;
    (*head_ref) = new_node;
}

void append(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref ==  NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

// Driver Code
int main(int argc, char **argv)
{
    struct Node *a = NULL;
    int i;

    i = 1;
    while(i < argc)//에러처리에러치리
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
    {
        append(&a, ft_atoi(argv[i]));
        i++;
    }
    printList(a);
    quick_sort(a, last_node(a));
    printList(a);
    return (0);
}