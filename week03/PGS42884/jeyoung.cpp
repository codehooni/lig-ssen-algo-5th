#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//routes의 두번쨰 값기준 오름차순 정렬하기 위한 비교함수
bool cmp(vector<int> a, vector<int> b) {
    if (a[1] < b[1]) return true;
    else return false;
}
//가장 빨리 진출한 차의 위치에 단속카메라를 설치하기 -> 지역해
//지역해를 반복하다보면 최적해
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int camera = -30001;
    for (int i = 0;i < routes.size();i++) {
        if (camera < routes[i][0]) {
            camera = routes[i][1];
            answer++;
        }
    }
    return answer;
}