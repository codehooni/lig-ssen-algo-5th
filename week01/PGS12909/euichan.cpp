#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    /**
    * 1. 핵심 로직: '('를 스택에 담고 ')'가 나와야지만 pop 하도록 했다.
    * 2. 선택 근거: '('와 ')'는 짝을 이루어야 하는데, 스택에 '('가 나올 때마다 쌓고 ')' 나올 때 제거하면 스택에
    * 남는 것이 있으면 문제가 있는 것이다. 
    */
    
    stack<char> s_stack;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s_stack.empty())
        {
            if (s[i] == ')') return false;
            s_stack.push(s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                s_stack.pop();
            }
            else
            {
                s_stack.push(s[i]);
            }
        }
    }
    
    if (s_stack.empty()) answer = true;
    else answer = false;

    return answer;
}