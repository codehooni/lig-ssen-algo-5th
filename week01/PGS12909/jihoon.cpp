/*

0. 선택 근거
- 프로그램을 하면서 스택 문제라는 것을 알고 있었다.

1. 아이디어
- 우선 '('는 무조건 stack에 넣는다.
- ')'를 만나면
    - stack의 size > 0 : stack.pop()
    - else : false
- 마지막으로 stack의 size == 0을 확인 후 맞으면 true 아니면 false

2. 시간복잡도
- O(N) < 100,000

3. 자료구조
- s: vector

*/

#include<string>
#include<stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    
    for(char& c : s) {
        if(c == '(') st.push('(');
        else {
            if(st.size() > 0) st.pop();
            else return false;
        }
    }
    
    if(st.size() != 0) answer = false;

    return answer;
}