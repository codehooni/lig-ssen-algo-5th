/*

0. 선택 근거:
- 가장 먼 정점끼리의 거리를 구해야하기 때문에 먼저 첫 번째로 가장 먼 정점을 구하고 거기서 가장 먼 거리를 구하면 지름이 된다.
- 모든 정점에서 탐색을 하게 되면 O(V^2)으로 100억이 나오므로 초과 -> DFS 2번으로 O(V)

1. 아이디어:
- 1번 정점에서 DFS로 가장 먼 정점(farNode)을 찾는다.
- farNode에서 다시 DFS를 돌려 가장 먼 거리를 구한다.

2. 시간복잡도:
- DFS 2번 → O(V), V ≤ 100,000

3. 자료구조:
- edge: 인접 리스트 vector<vector<pair<int,int>>> (정점, 거리)
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_V (100000 + 1)

int V;
bool visited[MAX_V];
vector<vector<pair<int, int>>> edge(MAX_V);
int farNode;
int farCost;

int dfs(int node, int cost);

int main() {

    cin >> V;  

    for(int i = 1; i <= V; i++) {
        int from, to, cost;
        cin >> from;

        while(cin >> to && to != -1) {
            cin >> cost;
            if(from == -1) break;
            edge[from].push_back({to, cost});
        }
    }
    dfs(1, 0);

    cout << dfs(farNode, 0);;

    return 0;
}

int dfs(int node, int cost) {
    if(visited[node]) return cost;
    visited[node] = true;

    if(farCost < cost) {farCost = cost; farNode = node;}

    int maxCost = cost;

    for(auto& [next, w]: edge[node]) {
        if(visited[next]) continue;
        maxCost = max(maxCost, dfs(next, cost + w));
    }

    visited[node] = false;

    return maxCost;
}