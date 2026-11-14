#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N 101

/*
    시간 복잡도: O(N^2) (N - 1개의 wires를 한번씩 끊으며 최대 N - 1개를 탐색)
    접근 방식: N의 범위가 작기 때문에 연결선을 한번씩 끊으며 완전 탐색을 수행함
    선택 근거:
        1. N이 작으므로 인접행렬 기반으로 그래프 생성
        2. 연결된 노드 수를 구하기 위해 dfs 수행
    핵심 로직:
        1. 연결선을 한번씩 0(끊음)으로 변경하고 dfs를 수행해 연결된 송전탑 수를 구함
        2. 송전탑 그룹 간 차이를 min과 비교해 갱신하고 연결선을 복귀해 반복함
*/

int visited[MAX_N];
int graph[MAX_N][MAX_N];

int dfs(int u, int n, int mark) {
    visited[u] = mark;
    
    int cnt = 1;
    for (int v = 1; v <= n; v++) {
        if (!graph[u][v] || visited[v] == mark) continue;
        cnt += dfs(v, n, mark);
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (auto v : wires) {
        graph[v[0]][v[1]] = 1;
        graph[v[1]][v[0]] = 1;
    }
    
    for (int i = 0; i < wires.size(); i++) {
        auto v = wires[i];
        graph[v[0]][v[1]] = 0;
        graph[v[1]][v[0]] = 0;
        int cnt = dfs(1, n, i + 1);
        answer = min(answer, abs(n - 2 * cnt));
        graph[v[0]][v[1]] = 1;
        graph[v[1]][v[0]] = 1;
    }
        
    return answer;
}