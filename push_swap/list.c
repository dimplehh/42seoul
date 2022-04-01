#include "header.h"

void insert(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node* prev = tail->prev;//tail의 앞
    node->prev = prev;//새 노드와 앞 노드를 연결
    prev->next = node;//새 노드와 앞 노드 연결(위와 동일. 양방향 구축 성공)
    node->next = tail;//tail과 새 노드를 연결함으로써 tail앞, 가장 마지막에 넣음
    tail->prev = node;//tail과 새 노드를 연결(위와 동일. 양방향 구축 성공)
}

// 삭제
void removeFront()
{
    Node* node = head->next;
    head->next = node->next;//앞에 오는 ->next는 노드 안의 next를 의미하고 뒤에오는거는 노드 자체를 의미.
    Node* next = node->next;
    next->prev = head;
    free(node);
}

// 리스트 출력
void show()
{
    Node* cur = head->next;
    while (cur != tail) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}