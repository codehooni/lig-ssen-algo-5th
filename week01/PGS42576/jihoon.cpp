/*
0. 선택근거
- 처음에 무식하게 completion에 있는 요소들을 participant에 있는 요소들과 비교하려고 하니 시간복잡도가 O(N^2)이 나와서 실패
- 리스트를 간단하게 그려보니 정렬이 되어 있으면 좋겠다는 생각을 하게 되었다. 그러니 두 리스트를 정렬하고 비교를 하게 되면 최대 2 * NlogN + N 이 나오게 된다. 

1. 아이디어
- 우선 두 리스트를 오름차순으로 정렬한다.
- 첫번째 원소부터 비교를 하고 다르면 participant의 해당 요소를 반환한다.

2. 시간복잡도
- O(MNlogN) < 20 * 2 * 100,000 * log(100,000) + 100,000 * 20 ~= 72,000,000 < 1e8

3. 자료구조

*/

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < completion.size(); i++) {
        if(participant[i] != completion[i]) return participant[i];
    }
    
    return participant.back();
}