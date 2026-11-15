#include <iostream>
#include <vector>

using namespace std;
/*
1. 핵심 로직: 1번 노드에서 가장 먼 노드 N1에 대하여,
N1과 N1에서 가장 먼 노드 N2와의 거리가 트리의 지름이다.
즉, 1에서 가장 먼 노드 N1, N1에서 가장 먼 노드 N2를 구하는 문제
2. 선택 근거: 트리에서 dfs 탐색을 통해서 정점의 최대거리를 두 번 구하는 방법 사용
*/
#define MAX_V 10000
#define MAX_N 100000

int v;
int maxDist, maxNode;                    // maxDist: 현재 방문중인 노드에서 가장 먼 거리, maxNode: 현재 방문중인 노드에서 가장 먼 노드
vector<bool> visit(MAX_N + 1);           // 방문확인
vector<pair<int,int>> graph[MAX_N + 1];

// node에서 시작해 나머지 노드까지의 거리 기록
void dfs(int node, int dist)
{
    // 방문한 노드면 return
    if (visit[node]) return;
    
    // maxDist 갱신시 maxNode도 갱신 (node에서 최대거리)
    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }
    visit[node] = true; //방문 체크
    // 현재 정점에서 연결 된 정점들로 dfs 수행
    for (const auto& p : graph[node]) {
        int nextIdx = p.first;
        int nextDst = p.second;
        // 현재거리 + nextIdx노드 까지의 거리로 재귀호출
        dfs(nextIdx, nextDst + dist);
    }
}
int main()
{
    cin >> v;

    int startNode, locNode, dist;
    for (int i = 1; i < v + 1; i++)
    {
        cin >> startNode;
        while (true)
        {
            cin >> locNode;
            if (locNode == -1) break;
            cin >> dist;
            graph[startNode].push_back({ locNode, dist });
            graph[locNode].push_back({ startNode, dist });
        }
    }

    // 1번 노드에서 dfs로 탐색
    dfs(1, 0);

    // visit, maxDist 초기화
    visit.assign(visit.size(), false);
    maxDist = 0;

    // 1과 가장 먼 정점에서 다시 dfs 수행하여 트리의 지름 찾기
    dfs(maxNode, 0);

    cout << maxDist << endl;

    return 0;
}
