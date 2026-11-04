#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    /**
    * 1. 핵심 로직: 동명이인을 고려하여 completion을 인덱스 삼아 해당 해시테이블로 이름을 가진 사람의 수를 카운트하고,
    *              그 이후에 participant를 인덱스 삼아 똑같이 해시테이블로 이름을 가진 사람의 수를 카운트하여, completion에 없는 사람을 찾아낸다.
    * 
    * 2. 선택 근거: 문자열을 비교하는 것보다 해시테이블을 만들어 이름을 인덱스 삼아서 접근하는 것이 효율적이라고 생각했습니다.
    *              왜냐하면 참가자 수가 최대 100,000명 이기 때문에 시간 복잡도가 O(n^2)인 문자열 비교를 사용하면 시간 초과가 발생할 수 있기 때문에,
    *              해시테이블을 이용하여 O(n)으로 해결하는 것이 효율적이라고 판단했습니다.
    */

    unordered_map<string, int> completion_number;  // 동명이인을 선별하기 위한 completion counter
    
    string answer = "";
    
    // 1) completion을 인덱스 삼아 해당 이름을 가진 사람의 수를 담은 해시테이블 생성
    for (string person : completion)
    {
        completion_number[person] ++;
    }
    
    // 2) participant를 이용하여 비교
    for (string person : participant)
    {
        if (completion_number[person]) completion_number[person] --;
        else answer = person;
    }
    
    return answer;
}