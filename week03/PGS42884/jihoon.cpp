/*

0. 선택근거
- 이 문제를 보고 회의실을 잡는 문제가 떠올랐다.
- 회의실 문제는 끝나는 시간이 가장 빠른 순으로 정렬을 하고 Greedy를 따라 선택한다.
- 이 문제 또한 같은 방법으로 끝나는 구간을 오름차순 정렬하여 CCTV를 설치하여 접근하였다.

1. 아이디어
- 먼저 끝나는 시간이 빠른 순으로 오름차순 정렬한다.
- 가장 마지막 구간을 기억하고 그 구간을 지나는 차량은 넘어간다.
- 범위 안에 마지막 CCTV가 없을 경우 다시 CCTV를 마지막 구간에 설치한다.
- 위 과정을 반복한다.

2. 시간복잡도
- O(N) : N ⩽ 10,000

3. 자료구조
- lastCCTV: int
- answer: int

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; }

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int lastCCTV = -30001;
    for(auto& r : routes) {
        if(r[0] <= lastCCTV && lastCCTV <= r[1]) continue;
        
        lastCCTV = r[1];
        answer++;
    }
    
    return answer;
}