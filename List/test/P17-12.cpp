/**
 * @brief 17页题12（2013真题）：寻找多数元素（过半）(https://leetcode.cn/problems/majority-element/)
 */

#include "..\SqList.h"

int Majority(SqList L){
    int ret = L.data[0], cnt = 1;
    for(int i = 1; i < L.length; i++){
        if(L.data[i] == ret)cnt++;
        else{
            cnt--;
            if(!cnt){
                ret = L.data[i];
                cnt = 1;
            }
        }
    }
    return cnt > 0 ? ret : -1;
}

int main()
{
    SqList L;
    InitList(L);
    for(int i = 0; i < 8; i++) {
        cin>>L.data[i];
        L.length++;
    }
    int ans = Majority(L);
    cout<<ans<<endl;
    return 0;
}