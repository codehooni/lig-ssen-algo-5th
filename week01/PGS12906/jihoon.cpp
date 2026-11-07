/*
1. 아이디어
- 이전 숫자를 기억하는 변수를 만들고 이전 숫자와 같지 않을 때만 for문을 돌면서 배열에 넣는다.

2. 시간복잡도
- O(N) < 1,000,000

3. 자료구조
- bitMask: int
*/

#include <vector>
#include <iostream>

using namespace std;

#if 0

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prev = -1;
    
    for(int& a : arr) {
        if(prev == a) continue;
        
        answer.push_back(a);
        prev = a;
    }
    
    return answer;
}

#endif

/*

erase, unique 함수를 이용한 풀이

*/

#if 1

#include <algorithm>

vector<int> solution(vector<int> arr) 
{    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    return arr;
}

#endif