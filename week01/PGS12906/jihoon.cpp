/*
1. 아이디어
- 이전숫자를 배열의 마지막 원소로 생각하고 비교한다.

2. 시간복잡도
- O(N) < 1,000,000

3. 자료구조
- bitMask: int
*/

#include <vector>
#include <iostream>

using namespace std;

#if 1

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    answer.push_back(arr.front());

    for(auto it = arr.begin() + 1; it != arr.end(); it++) {
        if(answer.back() == *it) continue;
        answer.push_back(*it);
    }
    
    return answer;
}

#endif

/*

erase, unique 함수를 이용한 풀이

*/

#if 0

#include <algorithm>

vector<int> solution(vector<int> arr) 
{    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    return arr;
}

#endif