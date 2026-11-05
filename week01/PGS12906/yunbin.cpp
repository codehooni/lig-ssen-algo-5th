
#include <vector>
using namespace std;



/*

 1. 핵심 로직: 
    - 연속적으로 나타나는 수이기에 그 이전값만 비교하면 된다. 
      따라서 이전값과 현재값을 비교하여 다르면 answer에 push_back한다.

 2. 선택 근거: 
    - 시간복잡도: O(n)으로 n은 arr의 길이이다.
    o(n)보다 빠른 알고리즘이 생각이 나지않았다.

 
 */

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    for (int num : arr) {
        if (answer.empty() || answer.back() != num) {
            answer.push_back(num);
        }
    }

    return answer;
}
