
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    // 첫 번째 원소를 미리 삽입
    answer.push_back(arr[0]);

    // 두 번째 원소부터 순회하며 연속된 중복 제거
    for (int i = 1; i < arr.size(); i++) {

        // 마지막으로 저장한 값과 현재 값이 다를 때만 삽입
        if (answer.back() != arr[i]) {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}
