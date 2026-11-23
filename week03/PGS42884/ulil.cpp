#include <string>
#include <vector>
#include <algorithm>  
using namespace std;

//1. 핵심 로직: 차들을 나간 지점이 빠른 순서(오름차순)로 정렬하고, 앞에서부터 하나씩 본다.
//              지금 차가 들어온 지점이 마지막 카메라 위치보다 오른쪽이면 그 카메라를 못 지나므로,
//              이 차가 나가는 지점에 새 카메라를 달고 개수를 1 늘린다.
//              들어온 지점이 카메라보다 왼쪽이거나 같으면 이미 카메라를 지나가므로 아무것도 안 한다.
//2. 선택 근거: 가장 먼저 나가는 차는 그 지점이 지나면 도로에 없으므로 가장 먼저 챙겨야 한다.
//              카메라를 그 차의 나간 지점(가장 오른쪽)에 달아야 뒤에 오는 차들까지 최대한 같이 찍을 수 있다.
//              나간 지점 순서로 정렬했기 때문에 카메라 위치는 점점 오른쪽으로 가고,
//              그래서 마지막 카메라 하나만 기억하고 비교해도 충분하다.
//              camera는 지점 범위(-30000 ~ 30000)보다 작은 -30001로 시작해서, 첫 차에는 무조건 카메라를 단다.

bool cmp (vector<int> a, vector<int> b){ //오름차순
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camera = -30001;
    
    sort(routes.begin(), routes.end(), cmp);
    for(int i = 0; i < routes.size(); i++){
        int in = routes[i][0];
        int out = routes[i][1];
        if(in > camera){ //카메라를 지나쳤는지 확인
            camera = out;
            answer++;
        }
    }

    return answer;
}
