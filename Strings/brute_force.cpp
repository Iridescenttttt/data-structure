#include<iostream>
using namespace std;

int bruteMatch(string source, string pattern) {
    int i = 0, j = 0;
    while(i < source.length() && j < pattern.length()){
        if(source[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    return j == pattern.length()? i - j : -1;
}

int main()
{
    
    return 0;
}