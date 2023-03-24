#ifndef SQSTACK_H
#define SQSTACK_H

#include<iostream>
using namespace std;

#define MaxSize 50                                          //栈最大长度
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

bool Push(SqStack &S, ElemType e) {
    if(S.top == MaxSize - 1)return false;
    S.data[++S.top] = e;
    return true;
}

bool Pop(SqStack &S, ElemType &e) {
    if(S.top == -1)return false;
    e = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &e) {
    if(S.top == -1)return false;
    e = S.data[S.top];
    return true;
}

#endif