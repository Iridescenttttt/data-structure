#include<iostream>
using namespace std;

int* getNext(string s) {
    int len = s.length();
    int *next = new int[len];
    next[0] = -1;                                                           //0、1位置自己定义
    if(len > 1)next[1] = 0;
    int cur = 0, i = 2;
    while(i < len){
        if(s[cur] == s[i - 1])next[i++] = ++cur;
        else if(cur > 0)cur = next[cur];
        else next[i++] = 0;
    }
    return next;
}

int KMP(string source, string pattern) {
    int *next = getNext(pattern);
    int i = 0, j = 0;
    while(i < source.length() && j < pattern.length()){
        if(source[i] == pattern[j]){
            i++;
            j++;
        }
        else if(j == 0) i++;
        else{
            j = next[j];
        }
    }
    return j == pattern.length()? i - j : -1;
}

int main()
{
    
    return 0;
}