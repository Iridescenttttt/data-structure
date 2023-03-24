#ifndef SQQUEUE_H
#define SQQUEUE_H

#include<iostream>
using namespace std;

#define MaxSize 50
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, ElemType e) {
    if((Q.rear + 1) % MaxSize == Q.front)return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e) {
    if(Q.front == Q.rear)return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

#endif