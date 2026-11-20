#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 선택 근거: routes를 진출 지점 오름차순으로 정렬한 뒤, 맨 앞 차량의 진출 지점에 카메라를 설치. 마지막으로 설치된 카메라가 뒤쪽 차량을 탐지 불가일 때 신규 카메라를 추가하면 전체 개수 최소화 가능.
// 핵심 로직:
// 1.routes를 routes[i][1] 오름차순으로 정렬. routes[0][1]에 카메라를 설치.
// 2.신규 차량의 진입점이 카메라 설치 지점보다 클 경우,해당 차량의 진출점에 신규 카메라 설치.
// 3.모든 차량에 대하여 위 과정 반복.
// 시간 복잡도: O(NlogN) - 오름차순 정렬 과정.

// 정렬 비교용 bool
bool compare_exit(const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    }

int solution(vector<vector<int>> routes) {
    // routes를 routes[i][1] 오름차순 정렬
    sort(routes.begin(),routes.end(),compare_exit);
    
    int answer = 1;
    int camera_point=routes[0][1];
    
    for(int i=1;i<routes.size();i++){
        if(camera_point<routes[i][0]){
            answer+=1;
            camera_point=routes[i][1];
        }
    }
    return answer;
}