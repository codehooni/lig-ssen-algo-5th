#include<string>
#include <iostream>
#include <stack>
using namespace std;
// 핵심 로직: Stack
// 선택 근거: 닫는 괄호 ')'가 나오면 항상 가장 최근의 나온 여는 괄호 '('에 대응되므로 stack이 적절할 것이라 생각했습니다
// 시간 복잡도: O(N) 


// 1번 풀이: 
// 1. s 내부에 char 들을 탐색하는 도중에는 닫는 괄호 ')'의 개수가 여는 괄호 '(' 보다 항상 작아야 한다
// 2. for문을 돈 다음에는 '('와 ')'의 개수가 동일하여야 한다
// bool solution(string s)
// {
//     bool answer = true;
//     int left_cnt =0;
//     int right_cnt =0;
//     // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
//     cout << "Hello Cpp" << endl;
//     for (int i=0;i<s.length();i++) {
//         if (s[i]=='(')
//             left_cnt +=1;
//         else if (s[i]==')')
//         {
//             right_cnt +=1;
//             if (left_cnt < right_cnt)
//                 return false;
//         }
//     }
    
//     if (left_cnt != right_cnt) return false;
//     return answer;
// }

// 2번 풀이: 전형적인 Stack
bool solution(string s) {
    bool answer = true;
    stack<char> st;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='(') st.push(s[i]);
        
        if (s[i]==')') {
            if (st.empty())
                return false;
            st.pop();
        }
    }
    
    if (!st.empty()) return false;
    return answer;
}