/**
 * @brief 17页题11（2011真题）：找出两个等长升序序列的中位数(https://leetcode.cn/problems/median-of-two-sorted-arrays/)
 */

#include "..\SqList.h"

int FindMid(SqList L1, SqList L2){
    int p = 0, q = 0;
    int len = L1.length;
    while(1){
        if(p + q < len - 1){
            if(L1.data[p] < L2.data[q]) p++;
            else q++;
        }
        else{
            return L1.data[p] < L2.data[q] ? L1.data[p] : L2.data[q];
        }
    }
}

int main()
{
    SqList L1, L2;
    InitList(L1);
    InitList(L2);
    for(int i = 0; i < 5; i++) {
        cin>>L1.data[i];
        L1.length++;
    }
    for(int i = 0; i < 5; i++) {
        cin>>L2.data[i];
        L2.length++;
    }
    int ans = FindMid(L1, L2);
    cout<<ans<<endl;
    return 0;
}