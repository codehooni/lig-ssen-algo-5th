#include <string>
#include <vector>
#include <cctype>

using namespace std;

/*
    시간 복잡도: O(N) (N은 문자열 길이)
    접근 방식: 각 단계별 함수를 구현하여 문자열을 순서대로 가공하는 방식으로 처리함
    선택 근거: 특별히 사용한 자료구조나 알고리즘이 없음.
    핵심 로직: 시간 복잡도를 줄이기 위해 원본 id는 수정하지 않고 단계별 새로운 id를 만듬
*/

string step_1(const string& s) {
    string temp = "";
    char offset = 'a' - 'A';
    
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') temp += c + offset;
        else temp += c;
    }
    
    return temp;
}

string step_2(const string& s) {
    string temp = "";
    
    for (char c : s) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.') {
            temp += c;
        }
    }
    
    return temp;
}

string step_3(const string& s) {
    string temp = "";
    
    for (char c : s) {
        if (temp.back() != '.' || c != '.') temp += c;
    }
    
    return temp;
}

string step_4(const string& s) {
    int start = 0, end = s.size();
    if (s.front() == '.') start++;
    if (s.back() == '.') end--;
    return s.substr(start, end - start);
}

string step_5(const string& s) {
    return s.size() == 0 ? "a" : s;
}

string step_6(string& s) {
    string temp = s.substr(0, 15);
    if (temp.back() == '.') temp.pop_back();
    return temp;
}

string step_7(string& s) {
    string temp = s;
    while (temp.size() < 3) temp += temp.back();
    return temp;
}

string solution(string new_id) {
    string step1 = step_1(new_id);
    string step2 = step_2(step1);
    string step3 = step_3(step2);
    string step4 = step_4(step3);
    string step5 = step_5(step4);
    string step6 = step_6(step5);
    string answer = step_7(step6);
    return answer;
}