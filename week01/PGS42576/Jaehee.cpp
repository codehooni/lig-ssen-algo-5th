#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
//핵심 로직:을 이용하여 참여자(participant)를 +1로 카운팅, 이후 완주자(completion)에 있는경우 -1로
//하나씩 카운팅을 제거해가면서 남아있는 카운트로 완주하지 못한 사람을 색출함.
//선택 근거: 맨 처음 이중반복문으로 카운팅을 하였을 때 일부 케이스는 성공하지만, 시간복잡도 때문에 안되는 케이스가 많아
//다른 방법을 찾아보다가 의찬님이 시간복잡도가 낮은 해시를 이용하는게 어떻겠냐는 제안을 해주셔서 unorderedmap을 이용하여,
//풀어보았다.
//해시는 딕셔너리처럼 문자열 배열 안의 값을 키-밸류로 저장하게 해준다. 그렇기에 반복문을 한번만 돌려도 체크가 가능하다.
//이중반복문을 이용하면 시간복잡도가 O(n^2)이지만, 해시를 이용하면 O(n)이 된다.
//
string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    
    int part = participant.size();
    int winner = completion.size();
    
    unordered_map<string, int>win;
    
    
        
    for(int i=0; i<part; ++i){
        win[participant[i]] += 1;
    }
    for(int i=0; i<winner; ++i){
        win[completion[i]] -= 1;
    }
    for(int i=0 ; i<part; ++i){
        if(win[participant[i]]>0) answer = participant[i];
    }
    
   return answer;
}