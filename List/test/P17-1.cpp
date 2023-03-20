/**
 * @brief 17页题1：删除最小元素（唯一）并返回
 */

#include "..\SqList.h"

int FindMin(SqList &L) {
    int len = L.length;
    if(len < 1){
        cout<<"Empty!"<<endl;
        return -1;
    }
    int min = 0;
    for(int i = 1; i < len; i++){
        if(L.data[i] < L.data[min])min = i;
    }
    int ret = L.data[min];
    L.data[min] = L.data[len - 1];
    L.length--;
    return ret;
}

int main()
{
    SqList L;
    InitList(L);
    cout<<"Please input nine number."<<endl;
    for(int i = 0; i < 9; i++) {
        cin>>L.data[i];
        L.length++;
    }
    int m = FindMin(L);
    cout<<m<<endl;
    for(int i = 0; i < L.length; i++){
        cout<<L.data[i]<<" ";
    }
    return 0;
}