#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
#define MAX_N 100
/*
1. 핵심 로직: 각 노드의 방문여부 visited를 사용하여 트리에 연결된 노드의 개수 cnt를 조정하는 재귀함수 dfs(n,wires, i)를 생성
dfs를 재귀호출하여 cnt를 구한뒤, 다른 트리와의 개수 차이를 최소값으로 갱신
2. 선택 근거: 시간복잡도는 O(N^3)으로 높으나, N이 최대 100으로 낮기 때문에 성공하였음.
인접리스트를 별도로 작성하지 않고 직관적이고 간결하게 작성하였음.
*/
// 노드의 방문여부 확인용 visited
vector<bool> visited(MAX_N + 1, false);
// 연결된 노드 개수 cnt
int cnt;

// i번째 간선을 제외하고, [i][0]에서 시작하는 트리의 연결된 노드 개수 반환
void dfs(int n, const vector<vector<int>>& wires, int i) {
    for (int j = 0; j < n - 1; j++) {
        if (j == i) continue;   // i번째 간선은 건너뜀
        int s = wires[j][0];
        int e = wires[j][1];
        // j번째 간선의 두 노드 중 하나만 방문했을 경우 갱신
        if (visited[s] ^ visited[e]) {
            // 방문하지 않은 노드를 방문처리
            visited[s]=visited[e]=true;
            // 연결된 노드 수를 증가시켜서 재귀호출
            cnt++;
            dfs(n, wires, i);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX_N + 1;

    for (int i = 0; i < n - 1; i++) {
        // visited 초기화 (1 ~ n)
        visited.assign(n + 1, false);

        // visited, cnt 초기화
        visited[wires[i][0]] = true;
        cnt = 1;
        // dfs 탐색을 [i][0] 노드부터 시작
        dfs(n, wires, i);
        // 두 트리의 차를 최소값으로 갱신
        answer = min(answer, abs(abs(n - cnt) - cnt));
        cnt = 0;
    }
    return answer;
}
