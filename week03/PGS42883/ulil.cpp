#include <string>
#include <vector>

using namespace std;
//1. 핵심 로직: 숫자를 앞에서부터 하나씩 answer에 남기는데, 넣기 전에 answer의 마지막 숫자가 지금 숫자보다 작으면 빼고 k를 1 줄인다.
//              큰 숫자 하나가 앞의 작은 숫자 여러 개를 연달아 뺄 수 있어서 if가 아니라 while로 반복한다.
//              빼는 걸 다 한 뒤에 지금 숫자를 넣는다. 먼저 넣으면 자기 자신과 비교하게 돼서 아무것도 못 뺀다.
//              끝까지 가도 k가 남으면(내림차순이나 같은 숫자만 있을 때) 뒤쪽이 가장 작으므로 뒤에서 k개를 지운다.
//2. 선택 근거: 자릿수가 같으면 앞자리가 큰 수가 무조건 크므로, 매 순간 앞자리를 더 크게 만드는 선택을 하는 그리디로 풀었다.
//              숫자의 순서는 바꿀 수 없고 빼기만 할 수 있어서, 정렬하지 않고 원래 순서대로 보면서 마지막에 남긴 숫자와 비교했다.
//              숫자가 최대 1,000,000자리라 모든 경우를 다 해 볼 수 없어서, 한 번만 훑는 스택 방식을 썼다.

string solution(string number, int k) {
    string answer = "";
        
    for (char c : number){
        while(!answer.empty() && answer.back() < c && k > 0){
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }
    answer.erase(answer.size() - k);    
    return answer;
}
