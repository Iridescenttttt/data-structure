#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include<iostream>
using namespace std;

#define ElemType int 

struct LinkNode {
    ElemType data;
    struct LinkNode *next;
};

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = new LinkNode;
    Q.front->next = nullptr;
}

bool QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(LinkQueue &Q, ElemType e) {
    LinkNode *p = new LinkNode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}

bool DeQueue(LinkQueue &Q, ElemType &e) {
    if(Q.front == Q.rear)return false;
    LinkNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)Q.rear = Q.front;                                              //原队列只有一个节点
    free(p);
    return true;
}

#endif