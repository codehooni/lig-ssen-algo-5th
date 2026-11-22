#include <string>
#include <vector>

using namespace std;

// 풀이 방법: Greedy Algorithm 
// 알고리즘: answer string을 stack처럼 활용한다
// 시간복잡도: O(N+K)
string solution(string number, int k) {
    string answer = number.substr(0, 1);
  
    // Step 1: answer string을 stack 처럼 활용하며 복사한다 
    for (int i=1;i<number.length();i++){
        while(k>0 && !answer.empty() && number[i]>answer.back()){
            answer.pop_back();
            k--;
        }
        answer+=number[i];
    }
    
    // Step 2: 삭제 할 리스트가 남겨져 있는 경우
    // if (k>0)
    //     answer=answer.substr(0,answer.length()-k);
        
   return answer.substr(0, answer.length() - k);
}