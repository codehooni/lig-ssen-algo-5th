#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> st;

    for (int i = 0;i < s.size();i++) {
        if (s[i] == '(') {
            st.push_back('(');
        }
        else {
            if (st.empty()) {
                return false;
            }
            if (st.back() == '(') {
                st.pop_back();
            }
        }

    }
    if (st.empty()) {
        return true;
    }
    else {
        return false;
    }

    return answer;
    
}