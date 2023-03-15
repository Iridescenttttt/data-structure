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

/**
 * @brief 头插法建立链表
 * 
 * @param head 头指针
 * @return LinkList 返回链表
 */
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

/**
 * @brief 尾插法建立链表
 * 
 * @param head 头指针
 * @return LinkList 返回链表
 */
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

/**
 * @brief Get the Elem object
 * 
 * @param L LinkList
 * @param pos position
 * @return LNode* 节点
 */
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

/**
 * @brief 查找某个值是否在链表中
 * 
 * @param L LinkList
 * @param val value
 * @return LNode* 节点
 */
LNode* LocateElem(LinkList head, int val) {
    LNode *p = head->next;
    while(p){
        if(p->data == val)return p;
        p = p->next;
    }
    return nullptr;
}

/**
 * @brief 链表插入
 * 
 * @param head 头指针
 * @param pos position
 * @param val value
 */
void ListInsert(LinkList &head, int pos, int val) {
    if(pos < 1)return ;
    LNode *p = GetElem(head, pos - 1);                                  //找到要插入位置的上一位置的指针
    LNode *q = new LNode;
    q->data = val;
    q->next = p->next;
    p->next = q;
}

/**
 * @brief 删除链表元素
 * 
 * @param head 头指针
 * @param pos position
 */
void ListDelete(LinkList &head, int pos) {
    if(pos < 1)return ;
    LNode *p = GetElem(head, pos - 1);
    if(p->next)p->next = p->next->next;
}

/**
 * @brief 重载
 * 
 * @param out 
 * @param head 
 * @return ostream& 
 */
ostream& operator<<(ostream &out, LinkList head){
    LNode *p = head->next;
    while(p){
        out<<p->data<<" ";
        p = p->next;
    }
    return out;
}

int main() {
    LNode *head = ListTailInsert(head);
    LNode *p;

    //test GetElem
    p = GetElem(head, 8);
    if(p)cout<<p->data<<endl;

    //test LocateElem
    p = LocateElem(head, 1);
    if(p)cout<<p->data<<endl;

    //test ListInsert
    ListInsert(head, 9, 9);
    cout<<head<<endl;

    //test ListDelete
    ListDelete(head, 1);
    cout<<head<<endl;
    return 0;
}