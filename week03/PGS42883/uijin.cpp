#include <string>
#include <vector>
using namespace std;

// 선택 근거: 앞자리 숫자가 클수록 전체 수가 커지므로, 지워서 큰 값을 넣을 수 있을 때 지우는 것이 전체적으로 이득. 앞자리부터 작은 숫자를 제거하는 그리디 알고리즘 채택.
// 핵심 로직:
// 1.number의 각 문자를 앞에서부터 순서대로 확인.
// 2.제거하는 것이 가능하고(k > 0, !answer.empty()), answer의 마지막 숫자가 현재 숫자보다 작으면 마지막 숫자를 제거하고 k 감소.
// 3.더 이상 제거할 수 없으면 현재 숫자를 answer 뒤에 추가.
// 4.number의 모든 문자를 입력한 뒤에도 k>0이면 남은 횟수만큼 마지막 숫자를 제거.
// 시간 복잡도: O(N)

string solution(string number, int k) {
    string answer = "";
    int n=number.size();
    for(int i=0;i<n;i++){
        // 맨 뒷 자리를 지우는 것이 가능하며, 지워서 생기는 이득이 있는 동안 answer를 계속 제거.
        while( (k>0) && (!answer.empty()) && ( answer.back() < number[i] ) ){
            answer.erase(answer.size()-1,1);
            k-=1;
        }
        // 삭제 조건 미충족시 answer에 숫자를 추가.
        answer+=number.substr(i,1); 
    }
    
    // number를 전부 추가한 뒤에 k>0이면 남은 값만큼 answer 길이를 축소.
    answer=answer.substr(0,answer.size()-k);
    
    return answer;
}