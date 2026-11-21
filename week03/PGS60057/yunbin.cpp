#include <string>
#include <vector>
using namespace std;

// 총문자열 길이의 약수 들만큼 쪼개면될듯
// 쪼갠걸 어떻게 압축할거냐가 관건
// 자료구조를 복잡하지않게 엮어보자
// 압축하려면 문자열의 반복횟수를 알아야함
// 몇개의 문자열로 끊어서 확인할건지 알아야함
// 그리디니까 중간에 return문있으면 좋을듯
// 아!!!!!!!! 끊는 문자열의 개수 만큼 해쉬셋에 넣는거야
// 이것만 구현해보자
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int minLength;

void check(int n, string s) {
    string prev = "";
    string str = "";
    int num = 1;

    for (int i = 0; i < s.length(); i += n) {
        string st = s.substr(i, n);

        if (prev.empty()) {
            prev = st;
            continue;
        }

        if (prev == st) {
            num++;
            continue;
        }

        if (num > 1) {
            str += to_string(num);
        }
        str += prev;

        prev = st;
        num = 1;

        if (str.length() >= minLength) return;
    }

    if (num > 1) {
        str += to_string(num);
    }
    str += prev;

    minLength = min((int)str.length(), minLength);
}

int solution(string s) {
    minLength = s.length();

    for (int i = 1; i <= s.length() / 2; i++) {
        check(i, s);
    }

    return minLength;
}


