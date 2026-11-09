
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    vector<char> st;

    for (int i = 0; i < s.size(); i++) {

        // 여는 괄호는 스택에 삽입
        if (s[i] == '(') {
            st.push_back('(');
        }
        else {
            // 닫는 괄호가 나왔는데 스택이 비어 있다면
            // 짝이 맞지 않으므로 false 반환
            if (st.empty()) {
                return false;
            }

            // 짝이 맞는 여는 괄호 제거
            if (st.back() == '(') {
                st.pop_back();
            }
        }
    }

    // 모든 괄호가 짝을 이루었다면 스택이 비어 있음
    if (st.empty()) {
        return true;
    }
    else {
        return false;
    }
}
