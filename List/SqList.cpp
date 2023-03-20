#include <iostream>
#include "SqList.h"
using namespace std;

ostream& operator<<(ostream &out, SqList L) {
    for(int i = 0; i < L.length; i++){
        out<<L.data[i]<<" ";
    }
    return out;
}

int main() {
    SqList L;
    InitList(L);
    for(int i = 0; i < 9; i++) {
        L.data[i] = i;
        L.length++;
    }
    cout<<L<<endl;

    // test increase
    IncreaseList(L, 5);
    cout<<L.MaxSize<<endl;

    // test insert
    ListInsert(L, 5, 9);
    cout<<L<<endl;

    // test delete
    ListDelete(L, 1);
    cout<<L<<endl;

    // test getelem
    int val = GetElem(L, 1);
    cout<<val<<endl;

    // test locate
    cout<<LocateElem(L, 9)<<endl;
    return 0;
}