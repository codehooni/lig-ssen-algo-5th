#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

/*
1. 핵심 로직: char 단위의 문자 전처리 후 substr의 기능을 활용하여 문자열 단위 수정
2. 선택 근거: substr 방식은 연속되는 각 문자 하나하나를 다루는 것보다
            시간복잡도 적인 면에 있어서 문자열의 처리에 유리하다.
*/

string solution(string new_id) {
    int id_len = new_id.size();
    string temp = "";
    
    // 1) UpperToLower, 2) char = a~z,1~9, -, _, .
    for (char &c : new_id) {
        // 1단계: 모든 대문자를 소문자로 치환
        c = tolower(c);
        // 2단계: 알파벳소문자(97 = 'a'), 숫자(48 = '0'), -_.를 추가
        if (((c >= 97) && (c <= 122)) || ((c >= 48) && (c <= 57)) || strchr("-_.", c))  temp += c;
    }
    // 3) 연속되는 마침표 정리 .. -> .
    while (temp.find("..") != string::npos) temp.replace(temp.find(".."), 2, ".");
    // 4) 맨 앞 또는 맨 뒤의 . 제거 -> [0] = . or [end] = .
    if (temp.front()=='.') temp = temp.substr(1,temp.size());
    if (temp.back()=='.') temp = temp.substr(0,temp.size()-1);
    // 5) 빈문자열에 대입 -> "" = 'a'
    if (temp == "") temp = "a";
    // 6) 문자열 길이 줄이기 + 마침표처리
    if (temp.size() > 15) temp = temp.substr(0,15);
    if (temp.back()=='.') temp = temp.substr(0,temp.size()-1);
    // 7) 문자열 길이 늘리기
    while (temp.size() < 3) temp += temp.back();
    
    return temp;
}