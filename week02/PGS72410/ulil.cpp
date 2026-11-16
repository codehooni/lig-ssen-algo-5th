#include <string>
#include <vector>

using namespace std;

//문제의 1~7단계를 순서대로 하나씩 처리한다.
//              글자를 빼야 하는 2, 3단계는 원본에서 지우지 않고, 남길 글자만 새 문자열(s2, s3)에 담는다.
//              3단계는 마지막에 담은 글자(s3.back())가 마침표면 다음 마침표를 건너뛰어 하나로 합친다.
//              back(), front()를 쓰기 전에 empty()로 비어 있는지 먼저 확인한다.
//2. 선택 근거: 규칙대로 바꾸는 구현 문제라, 단계마다 나눠서 처리하면 어디서 틀렸는지 찾기 쉽다.
//              1단계는 글자를 직접 바꿔야 해서 참조(&c)로 받았다.

string solution(string new_id) {
    //1단게
    for (char& c : new_id) {
        c = tolower(c);
    }
    //2단계
    string s2 = "";
    for (char c : new_id) {
        if (islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.')s2 += c;
    }
    //3단계
    string s3 = "";
    for (char c : s2) {
        if (c == '.' && !s3.empty() && s3.back() == '.') {
            continue;
        }
        s3 += c;
    }
    //4단계
    if (!s3.empty() && s3.front() == '.') s3.erase(0, 1);
    if (!s3.empty() && s3.back() == '.') s3.erase(s3.size() - 1, 1);
    //5단계
    if (s3.empty()) s3 = "a";
    //6단계
    if (s3.size() >= 16) {
        s3 = s3.substr(0, 15);
        if (s3.back() == '.') {
            s3.erase(s3.size() - 1, 1);
        }
    }
    //7단계
    while (s3.size() <= 2) {
        s3 += s3.back();
    }


    return s3;
}
