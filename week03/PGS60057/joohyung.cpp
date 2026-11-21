#include <string>
#include <vector>

using namespace std;

// 풀이 방법: 완전 탐색
// 알고리즘: 문제에서 기술한 대로 완전 탐색을 진행한다
// 시간복잡도: O(N^2) (문자열의 길이가 1000이하이므로 문제가 되지 않는다고 판단했습니다.)

int solution(string s) {
    int answer = s.length();
    
    for (int i=1;i<s.length();i++){ // Step 1: 부분 문자열의 길이를 점차 증가해 나간다
        
        // if (s.length()%i){
        //     continue;
        // }
        string prev = s.substr(0,i); // 직전 부분 문자열을 저장하는 변수
        int record = 1; // 중복 횟수를 기록하는 변수
        int length = 0; // 압축되는 문자열의 길이를 기록하는 변수

        for (int j=i;j<s.length();j+=i){ // Step 2: 부분 문자열의 길이대로 문자열 탐색을 진행
            if(s.substr(j,i)==prev){ // Step2-1: 이전 부분 문자열과 동일한 경우 
                record +=1;
            }
            else { // Step 2-2: 이전 부분 문자열과 다른 경우
                length+=prev.length();
                if (record > 1) length+=to_string(record).length(); // 중복 횟수가 10이면 길이가 2증가되어야함 (초기에 고려하지 않아서 오답 발생)
                record=1;
                prev=s.substr(j,i);
            }
        }

        // Step 2-3: 마지막 부분 문자열 반영
        length+=prev.length();
        if (record > 1) length+=to_string(record).length();
        
        if (length < answer) answer = length;
    }
    
    
    return answer;
}