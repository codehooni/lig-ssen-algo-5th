#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 선택 근거: 두 명단을 정렬하고 순서대로 비교하면 participant에만 있는 선수 탐색 가능.
// 핵심 로직: 정렬된 명단을 앞에서부터 비교하며 이름이 다른 참가자를 반환. 끝까지 일치하면 참가자 명단의 마지막 선수를 반환.
// 시간 복잡도: O(N log N)

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    for(int i=0;i<completion.size();i++){
        if(participant[i]!=completion[i]){
            answer=participant[i];
            return answer;
        }
    }
    
    return participant.back();
}