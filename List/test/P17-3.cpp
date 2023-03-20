/**
 * @brief 17页题3：删除所有值为val的元素，要求时间复杂度O(n)，空间复杂度O(1)
 */

#include "..\SqList.h"

void DeleteVal(SqList &L, int val) {
    int cnt = 0;                                                        //既做计数器，又是下标
    for(int i = 0; i < L.length; i++){
        if(L.data[i] != val) L.data[cnt++] = L.data[i];
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
    int val;
    cin>>val;
    DeleteVal(L, val);
    for(int i = 0; i < L.length; i++){
        cout<<L.data[i]<<" ";
    }
    return 0;
}