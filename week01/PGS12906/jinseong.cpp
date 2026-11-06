#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    선택 근거: 주어진 입력 순서를 유지하며, 인접 항 간의 비교를 통해 중복을 제거해야 하므로 스택을 활용할 수 있다.
    핵심 로직: 현재 값과 스택의 탑에 위치한 값을 비교하여 동일하지 않는 경우에만 스택에 값을 추가한다.
*/

// 스택 활용 풀이
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    answer.push_back(arr.front());
    
    for (auto it = arr.begin() + 1; it < arr.end(); it++) {
        if (answer.back() == *it) continue;
        answer.push_back(*it);
    }
    
    return answer;
}

// unique 함수를 활용한 풀이
vector<int> solution(vector<int> arr) { 
    arr.erase(unique(arr.begin(), arr.end()), arr.end());      
    return arr;
}