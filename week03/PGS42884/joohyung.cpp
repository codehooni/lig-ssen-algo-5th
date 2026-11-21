#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * 풀이 방법: Greedy Algorithm
 *
 * 선택 근거:
 * - 가장 먼저 진출하는 차량의 진출 지점에 카메라를 설치하면,
 *   해당 차량을 단속하면서 다른 차량도 최대한 함께 단속할 수 있다.
 *
 * 핵심 로직:
 * 1. 차량을 진출 지점 기준으로 오름차순 정렬한다.
 * 2. 가장 먼저 진출하는 차량의 진출 지점에 카메라를 설치한다.
 * 3. 현재 차량의 진입 지점이 기존 카메라 위치보다 크면
 *    새로운 카메라를 설치하고 위치를 갱신한다.
 *
 * 시간복잡도: O(NlogN)
 */
int solution(vector<vector<int>> routes) {
    int answer = 0;
    // Step 1. 진출 지점을 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) { 
        return a[1] < b[1];
    });

     // Step 2. 첫 번째 차량의 진출 지점에 카메라 설치
    int end=routes[0][1]; 
    int count=1;

     // Step 3. 기존 카메라로 단속할 수 없는 차량에만 추가 설치
    for(int i=1;i<routes.size();i++){ 
        if (routes[i][0]<=end){ 
            count++;
        }
        else{ 
            answer++;
            count=1;
            end=routes[i][1]; // 새로운 집합 생성;
        }
    }
    answer++;
    return answer;
}