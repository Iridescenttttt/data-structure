#include<iostream>
using namespace std;

int* getNext(string s) {
    int len = s.length();
    int *next = new int[len];
    next[0] = -1;                                           //0、1位置自己定义
    if(len > 1)next[1] = 0;
    int cur = 0, i = 2;										//cur表示当前匹配的前后缀长度
    while(i < len){
        if(s[cur] == s[i - 1])next[i++] = ++cur;
        else if(cur > 0)cur = next[cur];					//很妙的一步，仔细琢磨
        else next[i++] = 0;									//cur = 0说明当前位置没有公共前后缀，置0
    }
    return next;
}

int KMP(string source, string pattern) {
    int *next = getNext(pattern);							//获取模式串的next数组
    int i = 0, j = 0;
    while(i < source.length() && j < pattern.length()){
        if(source[i] == pattern[j]){
            i++;
            j++;
        }
        else if(j == 0) i++;
        else j = next[j];
    }
    return j == pattern.length()? i - j : -1;
}

int main()
{
    
    return 0;
}