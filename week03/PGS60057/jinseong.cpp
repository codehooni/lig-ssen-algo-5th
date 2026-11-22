#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
    시간 복잡도: O(N^2) (N은 문자열 길이, for와 while이 중첩되나, 인덱스 점프함)
    접근 방식: 1부터 N/2까지 크기별로 압축 문자열을 만들어 최소 길이를 구하는 방식으로 접근.
    선택 근거: 문자열을 순차적으로 비교하고 카운팅하기 위해 vector를 스택처럼 활용.
    핵심 로직:
        1. 비교할 크기(1 ~ N/2)만큼 벡터 끝의 문자열과 문자를 하나씩 비교
        2. 모두 일치하면 카운트 증가, 일치하지 않으면 벡터에 새로운 문자열 추가
        3. 비교 시작 지점을 크기만큼 점프
        4. 압축된 문자열을 만들어 최소 길이 갱신
*/

bool isSame(string& s1, string& s2, int start) {
    int size = s1.size();
    if (s2.size() - start < size) return false;

    for (int i = 0; i < size; i++) {
        if (s1[i] != s2[start + i]) return false;
    }

    return true;
}

int encodedSize(vector<pair<string, int>>& v) {
    string res = "", s;
    int cnt;
    
    for (auto p : v) {
        tie(s, cnt) = p;
        if (cnt != 1) res += to_string(cnt);
        res += s;
    }

    return res.size();
}

int solution(string s) {
    int answer = s.size();
    int half = s.size() / 2;
    
    for (int i = 1; i <= half; i++) {
        vector<pair<string, int>> v = {{ s.substr(0, i), 1 }};
        
        for (int j = i; j < s.size(); j += i) {
            if (isSame(v.back().first, s, j)) {
                v.back().second += 1;
            } else {
                v.push_back({ s.substr(j, i), 1 });
            }
        }
        
        answer = min(answer, encodedSize(v));
    }

    return answer;
}