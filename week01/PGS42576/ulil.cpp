#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
//1. 핵심 로직: 참가자는 cnt를 1 올리고, 완주자 이름은 cnt를 1 내린다.
//              끝나고 cnt에서 숫자가 0보다 큰 이름이 완주하지 못한 사람이다.
//2. 선택 근거: unordered_map은 이름으로 칸을 바로 찾아서 끝낼 수 있다.

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> cnt;   // 이름 → 몇 명인지

    for (string name : participant) cnt[name]++;   // 참가자는 +1
    for (string name : completion) cnt[name]--;    // 완주자는 -1

    for (auto p : cnt) {
        if (p.second > 0) return p.first;   // 숫자가 남은 사람(p.second)을 반환(p.first)
    }
    return "";
}
