#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 핵심 로직: 해쉬 테이블 (unorderd_map 활용)
// 선택 근거: participant의 동일한 이름이 중복되어 나올 수 있다고 언급되어 있고, participant의 길이가 completion의 길이보다 1 길것으므로 Hash map을 활용
// 시간 복잡도: O(NS)

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> dict;
    for (int i=0;i<participant.size();i++) {
        dict[participant[i]]+=1;
    }
    
    for (int i=0;i<completion.size();i++) {
        dict[completion[i]]-=1;
    }
    
    for (auto it = dict.begin();it != dict.end();it++) {
        if (it -> second) return it->first;
    }
    return answer;
}