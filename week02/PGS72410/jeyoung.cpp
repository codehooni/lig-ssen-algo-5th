#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0;i < new_id.size();i++) {
        if (new_id[i] >= 65 && new_id[i] <= 90) {  // 1단계 대문자 소문자로
            answer += new_id[i] + 32;
            continue;
        }
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= 48 && new_id[i] <= 57) || (new_id[i] >= 97 && new_id[i] <= 122)) { //2단계

            if (new_id[i] == '.' && answer.back() == '.') { //3단계 스택 느낌으로다가
                continue;
            }
            answer += new_id[i];
        }

    }
    string n_answer = "";
    for (int i = 0;i < answer.size();i++) {
        if (answer[i] == '.' && (i == 0 || i == answer.size() - 1)) { //4단계 맨앞,맨뒤 . 제거
            continue;
        }
        else {
            n_answer += answer[i];
        }
    }
    if (n_answer.size() == 0) {  //5단계
        n_answer += 'a';
    }
    while (n_answer.size() >= 16) { //6단계
        n_answer.pop_back();
    }
    if (n_answer.back() == '.') {
        n_answer.pop_back();
    }

    while (n_answer.size() <= 2) { //7단계
        n_answer += n_answer.back();
    }

    return n_answer;
}