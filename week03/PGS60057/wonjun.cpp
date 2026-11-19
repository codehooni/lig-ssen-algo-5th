#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
문자열 줄이기:
문자열의 길이 n에 대해서, n > x인 x로 문자열을 자를 수 있다.
(이때 n < x*2이면 줄이는 의미가 없으므로 x <= n/2)
이때, x 크기로 나눠진 각 문자열중, 연속되는 것이 있다면
abc abc = 2 abc로 표현한다. (단, 압축되지 않는다면 숫자x)
이와 같은 방식으로 표현할때 가장 짧은 길이를 반환

s의 길이: 1 ~ 1000, n의 크기: 1 ~ (s/2 또는 500)
-> 문자열 s의 길이 n보다 작은 수 x1, x2 ,, xk에 대해서
s를 xk로 나눈 문자열 벡터 vector<string> sx에 대해,
sx[i] == sx[i+1]이면 합칠수 있고, 이어서 sx[i] == sx[i+2]이면 추가로 합친다.

시간복잡도: (x크기 조정순회) N/2 * divS(substr O(N) + divSize 갱신 순회 O(N))
          = O(N^2)
*/
int divS(int x, const string& s) {
    vector<string> sx;  // 시작점부터 x 크기로 나누어 sx에 삽입
    int divSize = 0;
    for (int i = 0; i <= s.size()/x; i++) {
        sx.push_back(s.substr(x*i,x));
    }
    
    // sx[0]을 기준으로 잡고 일치여부 확인
    string currs = sx[0];
    string nexts;
    int abst = 1;
    for (int i = 1; i < sx.size(); i++) {
        nexts = sx[i];
        // 이전과 같은 문자열이면 겹침
        if (nexts == currs) abst++;
        else {
            if (abst > 1) divSize += (to_string(abst).size());  // 중복시 숫자삽입
            divSize += x;
            // abst, currs 갱신
            currs = nexts;
            abst = 1;
        }
    }
    // 조각문자열의 누락방지 (aaa, bbb, c에서 c)
    if (sx.back().size() != x) divSize += sx.back().size();
    return divSize;
}

int solution(string s) {
    int answer = 1001;
    if (s.size() <= 1) return s.size(); // s의 크기가 1일때 divS 루프를 돌지 않음
    for (int i = 1 ; i <= s.size()/2; i++) {
        answer = min(answer, divS(i, s));
    }
    return answer;
}