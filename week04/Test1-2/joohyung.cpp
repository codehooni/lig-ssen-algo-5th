#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 알고리즘: Greedy 알고리즘
// 시간 복잡도: O(N log N) — 끝 시각 기준 정렬 O(N log N) + 한 번 순회 O(N)
// 세부 사항: 지난 주차 단속 문제와 거의 같은 구간 그리디입니다.
//           끝 시각이 가장 이른 드론의 끝 시각 e에 가동하면 [e, e+d]를 커버하고,
//           다음 드론의 시작 s가 e+d보다 크면 새로 가동합니다.
//           e와 d가 각각 최대 2×10^9라서 e+d가 int 범위(약 2.1×10^9)를 넘어
//           오버플로가 납니다. 그래서 가동 시각 radar를 unsigned int로 두고
//           덧셈도 unsigned int로 계산했습니다.

bool compare (vector<int> &a, vector <int> &b) {return a[1]<b[1];}
int solution(vector<vector<int>> drones, int d) {
    // 여기에 코드를 작성하세요.

    // Step 1: 드론이 사라지는 시간을 기준으로 올림차순으로 정렬
    sort(drones.begin(),drones.end(),compare); //
    unsigned int answer=0;
    int radar=drones[0][1];
    for (int i=1;i<drones.size();i++){
        if (drones[i][0]>d+radar){
            answer++;
            radar=drones[i][1];
        }
    }
    answer++; 
    return answer;
}
