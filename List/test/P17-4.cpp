/**
 * @brief 17页题4题5：删除（s,t）之间的元素
 */

#include "..\SqList.h"

void DeleteVal(SqList &L, int s, int t) {
    int cnt = 0;
    for(int i = 0; i < L.length; i++){
        if((L.data[i] <= s) || (L.data[i] >= t)) L.data[cnt++] = L.data[i];
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
    int s, t;
    cin>>s>>t;
    DeleteVal(L, s, t);
    for(int i = 0; i < L.length; i++){
        cout<<L.data[i]<<" ";
    }
    return 0;
}