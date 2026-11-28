#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
    시간 복잡도: O(NlogN) (N: drone 수)
    접근 방식: 드론을 끝점 기준으로 오름차 정렬하여 레이저가 켜진 동안 다음 드론이 구간에 들어오는지 검사하는 방식으로 접근
    선택 근거:
        1. 이전 레이저 가동 시간에 다음 드론이 포함되는지만 검사해 가동 횟수를 누적하면 되므로 그리디로 접근
        2. "드론의 끝점 + 레이저 가동 시간"의 최대 범위가 40억이므로, unsigned int로 레이저 가동 시간 기록
    핵심 로직
        1. 드론을 구간의 끝점 기준으로 오름차 정렬
        2. 각 드론을 순회하며, 끝점에 레이저를 가동시켜 "끝점 + 가동시간"에 다음 드론의 시작점이 포함되는지 확인
        3. 포함되지 않는 경우, 가동 횟수 1 증가 및 다음 레이저 가동 시간 갱신
*/

bool comp(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> drones, int d) {
    sort(drones.begin(), drones.end(), comp);

    int answer = 1;
    unsigned int last_on = (unsigned int)(drones[0][1] + d);

    for (int i = 1; i < drones.size(); i++) {
        if (last_on < drones[i][0]) {
            answer += 1;
            last_on = (unsigned int)(drones[i][1] + d);
        }
    }

    return answer;
}