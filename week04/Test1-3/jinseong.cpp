#include <string>
#include <vector>
#include <cctype>
#include <utility>

using namespace std;

/*
    시간 복잡도: 측정 어려움... gpt왈 최악의 경우 10억까지 갈 수도 있다하지만 극단적 케이스가 없었다 함.
        최악의 예: (1[1[1[...100[100[10[a]]] ... ]])
        문제 조건: 복원 글자 10만 제한과 코드 길이 3만 제한이 시간 복잡도를 줄여준 요소들
    접근 방식
        1. 가장 안쪽 괄호부터 해결하기 위해 재귀를 이용하여 접근
        2. 스택 오버플로우로 인해 스택을 기반으로 부분 문자열과 반복 횟수를 저장하며 안쪽 괄호부터 해결
    선택 근거: 괄호가 중첩될 수 있기 때문에 안쪽 괄호부터 해결하기 위해서는 스택이 필요하다고 판단
    핵심 로직
        1. 반복 횟수를 구하기 위해 숫자를 별도로 저장하고, 일반 문자는 현재(스택의 끝) 부분 문자열에 누적
        2. 여는 괄호('[')가 나오면, 새로 문자열을 누적하기 위해 반복 횟수와 함께 스택에 추가
        3. 닫는 괄호(']')가 나오면, 최근 부분 문자열을 반복 횟수만큼 이전 문자열에 추가하여 문자열 복원
*/

typedef struct _SubStr {
    string str;
    int cnt;
} SubStr;


// 스택 기반 풀이2 - 100% 성공
string decodeStr(string& s) {
    vector<SubStr> v = {{ "", 1 }}; // 부분 문자열과 반복 횟수를 저장
    string tmp = "", num = "";

    for (int i = 0; i < s.size(); i++) {
        char cur = s[i];
        if (cur == ']') {
            string substr = move(v.back().str); // 문자열 복사 없이 소유권만 이동한다 하여 개선
            int n = v.back().cnt;
            v.pop_back();
            // 최근 저장된 부분 문자열을 반복 횟수만큼 이전 문자열에 누적
            while (n-- != 0) v.back().str += substr; // 이 부분이 시간 복잡도에서 가장 문제인 부분           
        }
        else if (isdigit(cur)) num += cur;
        else if (cur != '[') v.back().str += cur; // 최근 저장된 부분 문자열에 누적
        else { // '['인 경우, 반복할 부분 문자열을 구하기 위해 반복 횟수를 계산해 스택에 저장
            v.push_back({ "", atoi(num.c_str()) });
            num = "";
        }
    }

    return v.back().str;
 }

// 재귀 기반 풀이1 - 95.x% 성공, 1개 실패 (스택 오버플로우 예상)
pair<string, int> decodeStr(int idx, string& s) {
    string str = "", num = "";
    int i = idx;

    for (; i < s.size(); i++) {
        char cur = s[i];
        if (cur == ']') break;
        else if (isdigit(cur)) num += cur;
        else if (cur != '[') str += cur;
        else {
            pair<string, int> res = decodeStr(i + 1, s);
            int n = atoi(num.c_str());
            while (n-- != 0) str += res.first;
            num = "";
            i = res.second;
        }
    }

    return { str, i };
}

string solution(string code) {
    return decodeStr(code);
}