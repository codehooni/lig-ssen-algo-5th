#include<string>
#include <iostream>
using namespace std;


/**
    1. 핵심 로직:
    -'('만 저장하면되기에 이를 변수의 증감으로 해결해보고자했다
    2. 선택 근거: 
    - 스택 라이브러리를 사용하지않고 해결할 수 있는 방법이기에 선택하였다.
 */

bool solution(string s)
{
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