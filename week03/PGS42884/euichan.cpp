#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_CAR (10000 + 2)
using namespace std;

/*
1. 핵심 로직: 출발지와 도착지 상관없이 겹치면 되므로 정렬을 하여 비교하면 되겠다 생각을 했다.
             그래서 요소 내부를 오름차순으로 정렬하고, 요소들끼리도 오름차순 정렬해서 가장 앞에 있는 요소를 기준으로 가장 최대가 되는 지점을 찾고,
             그 이후엔 이미 설치가 된 지점들은 제외하고, 그 이후 요소부터 같은 방식으로 놓을 위치를 찾는다. (그리디)
             그런데 이 방식은 다른 차량의 루트와 포개질 때마다 범위를 좁혀야 한다는 것을 찾기가 쉽지 않다. 이 부분 AI의 도움을 받았다.. 

2. 선택 근거: 1차원 이동이므로 수평선에 나타내면서 파악을 하면 좋을 것 같아서 그렇게 나열해보니, 출발지점과 도착지점이 바뀌어도 상관없음을 확인하고 정렬했다.
             또한, 가장 앞에 있는 (가장 낮은 숫자에서 시작하는) 요소를 기준으로 설치 위치를 파악하면 좋을 것 같아서 그렇게 코드를 짰더니 딱 들어맞았다.
*/

/*
1. 단속 카메라를 한 번은 만나도록
2. routes가 매개변수
3. 최소 몇 대의 카메라
N -> 1 ~ 10000
O(N^2)까지 가능

route[i][0] -> 진입 지점
route[i][1] -> 진출 지점

Range -30000 ~ 30000

중복 개수가 많은 것 활용

-20 -15
-14 -5
-18 -13
-5  -3

*/

int solution(vector<vector<int>> routes) {
    bool visited[MAX_CAR] = { 0 };
    int cnt = 0;

    for (vector<int> &it: routes)
    {
        sort(it.begin(), it.end());
    }

    sort(routes.begin(), routes.end());

    for (int i = 0; i < routes.size(); ++i)
    {
        if (visited[i]) continue;

        visited[i] = true;

        int min_val = routes[i][0];
        int max_val = routes[i][1];
        
        for (int j = i; j < routes.size(); ++j)
        {
            if (min_val <= routes[j][0] && routes[j][0] <= max_val ||
                max_val >= routes[j][1])
                {
                    visited[j] = true;
                    min_val = max(min_val, routes[j][0]); // 이걸 못 찾았었음.. 겹칠 때마다 값 범위를 갱신해서 시작 지점이 더 큰 거에 맞추어야 함..
                    max_val = min(max_val, routes[j][1]); // 이걸 못 찾았었음.. 겹칠 때마다 값 범위를 갱신해서 종료 지점이 더 작은 거에 맞추어야 함..
                }
        }

        ++cnt;
    }

    return cnt;
}
