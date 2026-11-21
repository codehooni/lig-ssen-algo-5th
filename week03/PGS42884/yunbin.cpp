#include <vector>
#include <algorithm>
using namespace std;

/*

핵심 로직:
    1. 경계값을 기준으로 차량의 출차 지점을 오름차순 정렬한다.
    2. 가장 먼저 출차하는 차량의 출차 지점에 CCTV를 설치한다.
    3. 해당 CCTV를 지나가는 차량들은 추가 설치할 필요가 없으므로 제외한다.
    4. 기존 CCTV를 지나가지 않는 차량이 나오면 해당 차량의 출차 지점에 새로운 CCTV를 
    설치한다.
    5. 모든 차량을 확인할 때까지 반복한다.

2. 선택 근거:

    처음에는 최소 진입 지점부터 최대 진출 지점까지 하나씩 이동하면서 차량을 검사하려고 했습니다.     그런데 이렇게 하면 모든 좌표를 확인해야 하므로 비효율적이라고 생각했습니다.

    그래서 경계값을 기준으로 진행하는 것이 좋겠다고 판단했습니다.

    가장 먼저 출차하는 차량의 출차 지점에 CCTV를 설치하면 해당 차량을 단속하면서 다른 차량까지     최대한 포함할 수 있겠더군요.

    따라서 출차 지점으로 정렬한 후, 기존 CCTV로 단속할 수 없는 차량이 나올 때만 추가로 설치하     는 방식으로 구현했습니다.
    
AI 활용:
    알고리즘 구현을 하지못했습니다. 출차를 기준으로 비교를 해보고싶었으나 어떻게 구현해야하는지
    막막하더군요 구현부분에서 초기 sort를 통해서 순서를 정하는 방식에 도움을 받았고 
    마지막 최종 결과물을 구하는 부분은 스스로 작성하였습니다. 
*/


int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camera = -30001;

    sort(routes.begin(), routes.end(),
        [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

    for (const auto& route : routes) {
        if (route[0] > camera) {
            answer++;
            camera = route[1];
        }
    }

    return answer;
}