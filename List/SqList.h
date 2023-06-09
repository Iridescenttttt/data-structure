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

void InitList(SqList &L) {
    L.data = new int[InitSize];
    L.MaxSize = InitSize;
    L.length = 0;
}

void IncreaseList(SqList &L, int size) {
    int *p = L.data;
    L.data = new int[InitSize + size];
    for(int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize += size;
    delete []p;
}

void ListInsert(SqList &L, int pos, int e) {
    if(pos < 1 || pos > L.length + 1)cout<<"Please input the right postion!"<<endl;                 //e是从1开始的
    if(L.length == L.MaxSize) IncreaseList(L, 5);
    for(int i = L.length + 1; i >= pos; i--){
        L.data[i] = L.data[i - 1];
    }
    L.data[pos - 1] = e;
    L.length++;
}

bool ListDelete(SqList &L, int pos, int &e) {
    if(pos < 1 || pos > L.length)cout<<"Please input the right postion!"<<endl;
    if(L.length == 0)return false;
    e = L.data[pos - 1];
    for(int i = pos; i < L.length; i++){
        L.data[i - 1] = L.data[i];
    }
    L.length--;
    return true;
}

int GetElem(SqList &L, int pos) {
    if(pos < 1 || pos > L.length)cout<<"Please input the right postion!"<<endl;
    return L.data[pos - 1];
}

int LocateElem(SqList L, int val) {
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == val)return i + 1;
    }
    return -1;
}

#endif