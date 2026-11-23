
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
1. 핵심 로직
    1. 문자열을 일정한 길이로 쪼갠다. (문제에서 힌트)
    2. 쪼갠 문자열을 압축한다.
    3. 압축은 쪼갤 길이를 받은 후, 해당 길이만큼 문자열을 비교한다.
    4. substr() 함수를 사용해 문자열을 추출하고,
       이전 문자열하고만 비교하면 된다.
       같으면 반복 횟수를 증가시키고, 다르면 압축 결과에 추가한다.
    5. 기존에 측정한 최솟값보다 압축 문자열의 길이가
       크거나 같으면 더 검사할 필요가 없으므로 반환한다.

2. 선택 근거
    문자열 압축을 어떻게 구현할지 하루 정도 고민해 보았다.
    그러다가 오늘 다시 10분 정도 고민했는데
    해결 방법이 눈앞에 보이더군요.

    초기에는 해시셋을 사용해 중복 문자열을 검사하려고 했습니다.
    (이유는 딱히 없습니다.)

    구현하는 도중
    '음? 이거 그냥 이전 문자열하고 비교만 하면 되는 거 아닌가?'
    하는 생각이 들었습니다.

    굳이 해시셋을 사용할 필요 없이 이전 문자열과
    반복 횟수만 관리하면 되겠더군요.

    문자열 압축 방법을 정하고 나니 이번에는
    문자열을 얼마만큼 쪼갤 것인지 범위를 생각해야 했습니다.

    처음에는 제곱근 이하의 길이만 확인하면 될 것이라고 생각했습니다.

    이후 더 줄일 방법으로 문자열 길이의 약수만 검사하는 것도
    고민했으나, 문자열이 정확하게 나누어떨어지지 않아도
    압축할 수 있다는 점 때문에 적용하지 못했습니다.

    결국 동일한 문자열이 최소 2번 반복될 수 있는
    문자열 길이의 절반까지 검사하도록 구현했습니다.

    3. AI 활용
        C++의 substr() 함수 문법을 검색해 참고했습니다.
        글 정리 ai썼어요 하핳
*/

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

        if (str.length() >= minLength)
            return;
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
