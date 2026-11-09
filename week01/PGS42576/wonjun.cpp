#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
1. 핵심 로직: 해시 자료구조를 이용하여 완주한 선수를 순차적으로 소거한 후, 남는 선수 출력
2. 선택 근거: 해시 자료구조를 사용하면 시간복잡도 O(n)안에 해결 가능하다.
*/

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // participant의 해시 plist
    unordered_multiset<string> plist;
    for (int i = 0; i < participant.size(); i++) plist.insert(participant[i]);
    
    // completion의 요소 c를 plist에서 탐색하고, 찾으면 제거
    for (auto c : completion) {
        auto iter = plist.find(c);
        if (iter != plist.end()) plist.erase(iter);
    }
    
    // 남아있는 plist의 요소 (=완주 실패) 반환
    return (*plist.begin());
}