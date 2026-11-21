#include <string>
#include <vector>

using namespace std;

/*
    시간 복잡도: O(N + k) (N은 number 수) 
    접근 방식: 앞자리 수가 클수록 큰 수이므로 앞에서부터 작은 수를 제거하는 방식으로 접근.
    선택 근거: 이전 수와 다음 수를 비교하며 제거하기 위해 string을 스택처럼 활용.
    핵심 로직: 숫자를 추가하며 다음 수와 비교하여 k == 0이 될 때까지 작은 수를 제거함
*/

string solution(string number, int k) {
    string answer = "";
    
    for (char num : number) {
        while (k != 0 && !answer.empty() && answer.back() < num) {
            answer.pop_back();
            --k;
        }
        
        answer += num;
    }
    
    while (k-- != 0) answer.pop_back();
    
    return answer;
}