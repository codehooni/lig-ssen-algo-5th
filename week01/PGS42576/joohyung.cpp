#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 풀이법: 해쉬 테이블을 사용하기

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