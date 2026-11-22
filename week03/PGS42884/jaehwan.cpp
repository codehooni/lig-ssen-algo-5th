// PGS 42884
// 단속카메라

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//가설 1: 차량을 객체로 설정하고 나가는 차량이 카메라를 안찍었을 경우 카메라를 설치하고 빠져나감 
//          -> 나가는 차량(객체)을 마땅히 추적할 방법이 생각이 안나서 버림
//가설 2: 차량의 흔적을 정수 배열에 남긴 다음, 수의 변화를 이용하여 카메라의 수를 셈
//          -> 규칙성이 보이지 않아서 실패
// -- 1시간 초과 --
// 의찬씨 피드백: 차량을 정렬하면 그리디 적용하기 좋게 바뀜.

// 1. 핵심 로직: -
// 2. 선정 이유: -


int solution(vector<vector<int>> routes) {
    // 여기에 코드를 작성하세요.
    int answer = 0;
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b)
                                            {
                                                return a[1] < b[1];
                                            });
//    for(int i = 0; i < routes.size(); i++)
//        cout << routes[i][0] << " " << routes[i][1] << endl;
    int lastCCTV = -39999;
    for(auto& r : routes) 
    {
        if(r[0] <= lastCCTV && lastCCTV <= r[1]) continue;
        lastCCTV = r[1];
        answer++;
    }
    return answer;
}