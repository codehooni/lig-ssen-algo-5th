/*

0. 선택근거:
- 처음에 그리디라고 생각은 했지만, O(N^2)짜리 알고리즘을 선택했다.
    - 모든 문자를 돌면서 가장 큰 수를 한 번더 안에서 찾았다.
- 그렇게 시간 초과가 나서 AI에게 문제의 방향을 도움 받았다.
- 처음에 넣었다가 빼는 방식이 얼마나 빼야하는지를 모른다고 생각했다. 
- 하지만 그 역할을 k가 해준 다는 것을 알게 되었다. 

1. 아이디어:
- 먼저 숫자를 그냥 다 넣는다.
- 내 숫자보다 뒤에 숫자가 더 작으면 지우고 넣는다.
- 숫자를 지울 때마다 k를 감소 시키고 k가 남지 않으면 더 이상 지우지 않는다.
- 다 돌고나서 k를 다 사용하지 못 할 경우 나머지 뒤에를 잘라준다.

2. 시간복잡도:
- O(N) : N ⩽ 1,000,000

3. 자료구조:

*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for(auto& c : number) {
        while(k > 0 && answer.size() > 0 && answer.back() < c) {
            answer.pop_back();
            k--;
        }
        
        answer.push_back(c);
    }
    
    answer.resize(answer.size() - k);
    
    return answer;
}