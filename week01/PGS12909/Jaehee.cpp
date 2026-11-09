#include<string>            
#include <iostream>
#include<stack>

using namespace std;
/*
핵심로직 : 스택사용
-stack에 '('를 push하고 ')'가 나올때마다 pop()을 하면서 예외일 경우엔 잘못된 괄호의 짝임
선정이유: 괄호의 짝을 맞추기 위해 스택을 사용하면 편리하다.


*/
bool solution(string s)
{
    stack<int> sta;            //괄호를 저장하기위한 스택 생성
    //cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            sta.push(s[i]);
            if(sta.empty()) return false;
        }
        if(s[i]==')'){
            if(sta.empty()) return false;
            else sta.pop();
        }
    }
    if(sta.empty()) return true;
    else return false;
}