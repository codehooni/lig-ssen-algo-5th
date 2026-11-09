#include <vector>
#include <iostream>

using namespace std;

int last_number;

// 선택 근거: 이전 숫자와 현재 숫자를 비교하면 연속된 중복 판별 가능.
// 핵심 로직: 이전 숫자와 다른 경우에만  last_number를 갱신해서 answer에 추가.
// 시간 복잡도: O(N)

vector<int> solution(vector<int> arr) 
{
    last_number=arr[0];
    vector<int> answer={arr[0]};
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=last_number){
            last_number=arr[i];
            answer.push_back(last_number);
        }
    }

    return answer;
}