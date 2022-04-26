#include "header.h"

void	DequeInit(t_Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(t_Deque* pdeq)
{
	if (pdeq->head == NULL)
		return 1;
	else
		return 0;
}

void	DQIndexing(t_Deque	*pdeq)
{
	t_Node* cur = pdeq->head;
	if (DQIsEmpty(pdeq))
		pdeq->head->index = 0;
	else
	{
		while (cur != pdeq->tail)
		{
			if(cur->data < pdeq->tail->data)
				pdeq->tail->index++;
			else
				cur->index++;
			cur = cur->next;
		}
	}
}

int	DQRemoveFirst(t_Deque* pdeq)
{
	t_Node* newNode = pdeq->head;
	int index;

	index = pdeq->head->index;
	pdeq->head = pdeq->head->next;
	if(pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev=NULL;
	// if (newNode)
	// 	free(newNode);
	return (index);
}

void    DQAddLast(t_Deque* pdeq, int data)
{
	t_Node* newNode = (t_Node*)malloc(sizeof(t_Node));
	newNode->data = data;
	newNode->prev = pdeq->tail;
	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;
	newNode->next = NULL;
	pdeq->tail = newNode;
	DQIndexing(pdeq);
}

void    DQAddFirst(t_Deque* pdeq, int index)
{
	t_Node* newNode = (t_Node*)malloc(sizeof(t_Node));
	newNode->index = index;
	newNode->next = pdeq->head;
	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;
	newNode->prev = NULL;
	pdeq->head = newNode;
}

int	DQsize(t_Deque	*pdeq)
{
	int	i;

	i = 0;
	t_Node* cur = pdeq->head;
	if (!DQIsEmpty(pdeq))
	{
		while (cur != pdeq->tail)
		{
			cur = cur->next;
			i++;
		}
		return (i + 1);
	}
	return (0);
}
