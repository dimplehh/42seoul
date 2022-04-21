#include "header.h"

void DequeInit(Deque* pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
    if (pdeq->head == NULL)
        return 1;
    else
        return 0;
}

void DQAddLast(Deque* pdeq, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdeq->tail;
    if (DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;
    newNode->next = NULL;
    pdeq->tail = newNode;
}

int DQsize(Deque* pdeq)
{
    int i = 0;
    Node* cur = pdeq->head;
    if (!DQIsEmpty(pdeq))
    {
        while (cur != pdeq->tail)
        {
            cur = cur->next;
            i++;
        }
        return i;
    }
    return 0;
}

void show(Deque* pdeq)
{
    Node* cur = pdeq->head;
    if (!DQIsEmpty(pdeq))
    {
        while (cur != pdeq->tail)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("%d ", cur->data);
    }
    printf("\n");
}