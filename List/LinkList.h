#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
using namespace std;

/**
 * @brief LinkList是LNode*，可以理解为LinkList表示整个链表（实则是指向头节点的指针），LNode表示节点
 * 
 */
typedef struct LNode{
    int data;
    LNode *next;
}*LinkList;

LinkList ListHeadInsert(LinkList &head) {
    head = new LNode;
    head->next = nullptr;
    LNode *p;
    int val;
    cin>>val;
    while(val != 9999){
        p = new LNode;
        p->data = val;
        p->next = head->next;
        head->next = p;
        cin>>val;
    }
    return head;
}

LinkList ListTailInsert(LinkList &head) {
    head = new LNode;
    head->next = nullptr;
    LNode *p, *q = head;                                                //q指向链表尾
    int val;
    cin>>val;
    while(val != 9999){
        p = new LNode;
        p->data = val;
        q->next = p;
        q = p;
        cin>>val;
    }
    q->next = nullptr;
    return head;
}

LNode* GetElem(LinkList head, int pos) {
    if(pos < 0)return nullptr;
    else if(pos == 0)return head;                                       //方便插入操作在第一个位置插入
    LNode* p = head->next;
    int cnt = 1;
    while(p && cnt != pos){
        p = p->next;
        cnt++;
    }
    return p;
}

LNode* LocateElem(LinkList head, int val) {
    LNode *p = head->next;
    while(p){
        if(p->data == val)return p;
        p = p->next;
    }
    return nullptr;
}

void ListInsert(LinkList &head, int pos, int val) {
    if(pos < 1)return ;
    LNode *p = GetElem(head, pos - 1);                                  //找到要插入位置的上一位置的指针
    LNode *q = new LNode;
    q->data = val;
    q->next = p->next;
    p->next = q;
}

void ListDelete(LinkList &head, int pos) {
    if(pos < 1)return ;
    LNode *p = GetElem(head, pos - 1);
    if(p->next)p->next = p->next->next;
}

ostream& operator<<(ostream &out, LinkList head){
    LNode *p = head->next;
    while(p){
        out<<p->data<<" ";
        p = p->next;
    }
    return out;
}

#endif