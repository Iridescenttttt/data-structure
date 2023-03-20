#ifndef SQLIST_H
#define SQLIST_H
#include<iostream>
using namespace std;

#define InitSize 10

struct SqList {
    int *data;
    int MaxSize;
    int length;
};

/**
 * @brief Init the list.
 * 
 */
void InitList(SqList &L) {
    L.data = new int[InitSize];
    L.MaxSize = InitSize;
    L.length = 0;
}

/**
 * @brief Increase the list length.
 * 
 * @param size increase size.
 */
void IncreaseList(SqList &L, int size) {
    int *p = L.data;
    L.data = new int[InitSize + size];
    for(int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize += size;
    delete []p;
}

/**
 * @brief Insert element to list.
 * 
 * @param pos insert position
 * @param e element
 */
void ListInsert(SqList &L, int pos, int e) {
    if(pos < 1 || pos > L.length + 1)cout<<"Please input the right postion!"<<endl;
    if(L.length == L.MaxSize) IncreaseList(L, 5);
    for(int i = L.length + 1; i >= pos; i--){
        L.data[i] = L.data[i - 1];
    }
    L.data[pos - 1] = e;
    L.length++;
}

/**
 * @brief Delete the element at the corresponding position.
 * 
 * @param pos position
 * @return int deleted element
 */
int ListDelete(SqList &L, int pos) {
    if(pos < 1 || pos > L.length)cout<<"Please input the right postion!"<<endl;
    int ret = L.data[pos - 1];
    for(int i = pos; i < L.length; i++){
        L.data[i - 1] = L.data[i];
    }
    L.length--;
    return ret;
}

/**
 * @brief Get the Elem object.
 * 
 * @param pos position
 * @return int element
 */
int GetElem(SqList &L, int pos) {
    if(pos < 1 || pos > L.length)cout<<"Please input the right postion!"<<endl;
    return L.data[pos - 1];
}

/**
 * @brief Find the element position
 * 
 * @param val value
 * @return int position
 */
int LocateElem(SqList L, int val) {
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == val)return i + 1;
    }
    return -1;
}

#endif