#include<string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    //int를 stack처럼 사용해보았사와요
    int n=0;
    for(char c:s){
        if(c=='(') n++;
        else if(n==0) return false;
        else n--;
    }

    if(n!=0)
        return false;

    return true;
}