#include <vector>
#include <iostream>

using namespace std;

/**
 * 1. 핵심 로직: 그 전 값과 비교해서 다르면 answer에 담는다.
 * 2. 선택 근거: 복잡한 방식보다 이전 값과 비교하는 단순한 로직이 시간복잡도가 낮을 것으로 생각했다.
 */

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (answer.empty() || answer.back() != arr[i]) answer.push_back(arr[i]);
    }

    return answer;
}