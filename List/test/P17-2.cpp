/**
 * @brief 17页题2：原地逆置L
 */

#include "..\SqList.h"

void Reverse(SqList &L) {
    int p = 0, q = L.length - 1;
    while(p < q){
        int tmp = L.data[p];
        L.data[p] = L.data[q];
        L.data[q] = tmp;
        p++;
        q--;
    }
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
    Reverse(L);
    for(int i = 0; i < L.length; i++){
        cout<<L.data[i]<<" ";
    }
    return 0;
}