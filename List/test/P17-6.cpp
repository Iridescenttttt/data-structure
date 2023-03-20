/**
 * @brief 17页题6：删除有序数组的重复元素
 */

#include "..\SqList.h"

void DeleteDup(SqList &L){
    int cnt = 1; 
    for(int i = 1; i < L.length; i++){
        if(L.data[i] != L.data[i - 1]) L.data[cnt++] = L.data[i];
    }
    L.length = cnt;
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
    DeleteDup(L);
    for(int i = 0; i < L.length; i++){
        cout<<L.data[i]<<" ";
    }
    return 0;
}