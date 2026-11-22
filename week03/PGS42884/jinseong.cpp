#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    시간 복잡도: O(NlogN) (=정렬 시간 복잡도)
    접근 방식: 끝점 기준으로 정렬하고 시작점과 이전 차량의 끝점 교차를 검사하는 방식으로 접근.
    선택 근거: 비교 지점과 교차하지 않으면 카메라를 추가해서 그리디 같긴한데 와닿지는 않음.
    핵심 로직
        1. 끝점 기준으로 내림차 정렬하고 시작점과 이전 차량의 끝점 비교
        2. 교차하지 않으면 카메라를 추가하고 시작점 갱신
        3. 교차하면 카메라 추가 없이 둘 중 더 먼 시작점으로 갱신 
*/

// 더 간단한 풀이 버전
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int end = 30001;
    
    sort(routes.begin(), routes.end(), greater());
    for (auto& r : routes) {
        if (end > r[1]) {
            answer += 1;
            end = r[0];
        }
    }
    
    return answer;
}

// 새로 푼 풀이 <-- 처음엔 이렇게 풀었고 이걸 기준으로 설명.
bool comp(vector<int>& a, vector<int>& b) {
    return a[1] > b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int end = 30001;
    
    sort(routes.begin(), routes.end(), comp);
    
    for (auto& r : routes) {
        if (end <= r[1]) end = max(end, r[0]);
        else {
            answer += 1;
            end = r[0];    
        }
    }
    
    return answer;
}