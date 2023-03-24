#ifndef LINKSTACK_H
#define LINKTACK_H

#include<iostream>
using namespace std;

#define ElemType int

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}*LinkStack;

void InitStack(LinkStack &head) {
    head = nullptr;
}

bool StackEmpty(LinkStack head) {
    return head == nullptr;
}

bool Push(LinkStack &head, ElemType e) {
    LinkNode *p = new LinkNode;
    p->data = e;
    p->next = head;                                                       //特别注意这两句，与有头结点的链是不同的
    head = p;
    return true;
}

bool Pop(LinkStack head, ElemType &e) {
    if(!head)return false;
    LinkNode *p = head;
    head = head->next;
    e = p->data;
    free(p);
    return true;
}

bool GetTop(LinkStack head, ElemType &e) {
    if(!head)return false;
    e = head->data;
    return true;
}

#endif