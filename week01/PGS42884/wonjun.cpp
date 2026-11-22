#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
차량 c: 1 ~ 10000
경로[i]: i번째 차량의 진입/진출 지점

1. 핵심 로직: 순서대로 정렬된 차량들에 대해서, 각 차량이 들어올 때 해당 차량의 진출지점에 카메라 설치
2. 선택 근거: routes 정렬에서 O(N logN), cam 설치에서 O(N)

*/

bool sortR(const vector<int>& r1, const vector<int>& r2) {
    return (r1[1] < r2[1]);
}

int solution(vector<vector<int>> routes) {
    if (routes.size() <= 1) return routes.size();
    // routes 진출 지점 순 정렬
    sort(routes.begin(), routes.end(), sortR);
    // 1번 차량 진출지점에 cam 설치
    int cam = routes[0][1];
    int answer = 1;
    
    for (auto r : routes) {
        // cam 설치 이후에 차량이 들어오면 진출지점에 cam 설치
        if (r[0] > cam) {
            answer++;
            cam=r[1];
        }
    }
    return answer;
}