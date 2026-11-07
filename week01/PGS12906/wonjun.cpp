#include <vector>
#include <iostream>

using namespace std;
/*
1. 핵심 로직: 연속되는 숫자가 나오면 1개만 담기 -> [현재값]과 [이전값]이 다를때만 담기
2. 선택 근거: 배열 순회: O(N), 숫자 대조:O(1) -> O(N)안에 해결 가능
*/


vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev = -1;

    for (int i : arr) {
        if (prev != i) answer.push_back(i);
        prev = i;
    }

    return answer;
}