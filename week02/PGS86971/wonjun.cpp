#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
#define MAX_N 100

// 노드의 방문여부 확인용 visited
vector<bool> visited(MAX_N + 1, false);
int cnt;

// i번째 간선을 제외하고, node에서 시작하는 dfs로 연결 노드 확인
// cnt로 연결된 노드 개수 반환
void dfs(int n, const vector<vector<int>>& wires, int i) {
    for (int j = 0; j < n - 1; j++) {
        if (j == i) continue;   // i번째 간선은 건너뜀
        int s = wires[j][0];
        int e = wires[j][1];
        // j번째 간선의 두 노드 중 하나만 방문했을 경우 갱신
        if (visited[s] ^ visited[e]) {
            // 방문하지 않은 노드 발견 시 방문처리
            visited[s] = visited[e] = true;
            // 연결된 노드 수를 증가시켜서 재귀호출
            cnt++;
            dfs(n, wires, i);
        }
    }
    // 현재까지의 cnt값 반환
    //return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX_N + 1;

    for (int i = 0; i < n - 1; i++) {
        // visited 초기화 (1 ~ n)
        visited.assign(n + 1, false);

        // dfs 탐색을 [i][0] 노드부터 시작
        int s = wires[i][0];
        visited[s] = true;
        cnt = 1;
        dfs(n, wires, i);

        answer = min(answer, abs(abs(n - cnt) - cnt));
        cnt = 0;
    }
    return answer;
}
