#include <iostream>
#include <stack>
using namespace std;

/*
    선택 근거: 입력 순서대로 인접한 괄호를 비교하며 짝을 이루는지 확인해야 하므로 스택을 활용할 수 있다.
    핵심 로직: 현재 괄호와 스택의 탑에 위치한 괄호를 비교하여, 잘못된 쌍을 이루면 false를 반환하고 아닌 경우 스택을 비워나간다.
*/

// 원래 문제 풀이 추가
bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    
    for (char c : s) {
        if (c == '(') stk.push(c);
        else if (stk.size() == 0) return false; 
        else stk.pop();
    }
    
    return stk.size() == 0;
}

// 괄호 2개로 착각한 풀이
bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    
    for (char c : s) {
        if (stk.size() == 0) {
            if (c == ')' || c == ']') return false;
            stk.push(c);
            continue;
        }

        char last_pair = stk.top() == '(' ? ')' : ']';
        if (last_pair == c) stk.pop();
        else if (c == '(' || c == '[') stk.push(c);
        else return false;
    }
    
    return stk.size() == 0;
}
