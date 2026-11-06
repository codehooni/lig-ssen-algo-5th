#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    선택 근거:
        참가자와 완주자를 모두 비교한다면 최대 10만명이기 때문에 10만 * 10만의 연산 횟수로 시간 초과가 발생한다.
        참가자 명단을 카운트하고 완주자만 제거한다면 미완주자를 구할 수 있기 때문에 해시 테이블을 활용할 수 있다. 
    핵심 로직: 해시 테이블(map)에 참가자 이름을 카운트하고 완주자 이름의 카운트를 감소시켜 미완주자 이름을 구한다.
*/

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> cnt;
    
    for (auto p : participant) {
        cnt[p] += 1;
    }
    
    for (auto c : completion) {
        cnt[c] -= 1;
    }
    
    for (auto p : cnt) {
        if (p.second != 0) return p.first;
    }

    return "";
}