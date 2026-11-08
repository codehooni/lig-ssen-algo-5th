
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    // 선수 이름별 참가 횟수를 저장할 map
    map<string, int> s;

    // 참가자 명단을 순회하며 이름별 등장 횟수 증가
    // map의 [] 연산자는 키가 없으면 기본값(0)으로 생성하므로
    // 별도의 find() 없이 등장 횟수를 증가시킬 수 있다.
    for (int i = 0; i < participant.size(); i++) {
        s[participant[i]]++;
    }

    // 완주한 선수의 등장 횟수 감소
    for (int i = 0; i < completion.size(); i++) {
        s[completion[i]]--;
    }

    // 참가 횟수가 남아 있는 선수가 완주하지 못한 선수
    for (int i = 0; i < participant.size(); i++) {
        if (s[participant[i]] > 0) {
            return participant[i];
        }
    }

    return "";
}
