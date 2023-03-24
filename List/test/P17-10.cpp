/**
 * @brief 17页题10（2010真题）：将数组循环左移p个位置(https://vjudge.net/problem/HackerRank-array-left-rotation)
 */

#include "..\SqList.h"

// void Move(SqList &L, int p){                                    //借助了辅助数组，空间复杂度O(n)
//     int len = L.length;
//     SqList temp;
//     InitList(temp);
//     for(int i = 0; i < len; i++){
//         temp.data[i] = L.data[i];
//         temp.length++;
//     }
//     for(int i = 0; i < len; i++){
//         L.data[(i + len - p) % len] = temp.data[i];
//     }
// }


//原地移动面临的问题是旧值的保存及如何遍历
void Move(SqList &L, int p){
    int len = L.length;
    
}

int main()
{
    SqList L;
    InitList(L);
    for(int i = 0; i < 9; i++) {
        cin>>L.data[i];
        L.length++;
    }
    int p;
    cin>>p;
    Move(L, p);
    for(int i = 0; i < L.length; i++){
        cout<<L.data[i]<<" ";
    }
    return 0;
}