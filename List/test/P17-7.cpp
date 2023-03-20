/**
 * @brief 17页题7：合并两个有序顺序表
 */

#include "..\SqList.h"

SqList Merge(SqList L1, SqList L2){
    SqList ret;
    InitList(ret);
    IncreaseList(ret, L1.length + L2.length - InitSize);
    int p = 0, q = 0, cur = 0;
    while(p < L1.length && q< L2.length){
        if(L1.data[p] < L2.data[q]){
            ret.data[cur] = L1.data[p];
            p++;
        }
        else{
            ret.data[cur] = L2.data[q];
            q++;
        }
        cur++;
    }
    for(int i = p; i < L1.length; i++){
        ret.data[cur++] = L1.data[i];
    }
    for(int i = q; i < L2.length; i++){
        ret.data[cur++] = L2.data[i];
    }
    ret.length = L1.length + L2.length;
    return ret;
}

int main()
{
    SqList L1, L2, L3;
    InitList(L1);
    InitList(L2);
    for(int i = 0; i < 9; i++) {
        cin>>L1.data[i];
        L1.length++;
    }
    for(int i = 0; i < 9; i++) {
        cin>>L2.data[i];
        L2.length++;
    }
    InitList(L3);
    L3 = Merge(L1, L2);
    for(int i = 0; i < L3.length; i++){
        cout<<L3.data[i]<<" ";
    }
    return 0;
}