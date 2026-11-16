/*
 1. 핵심 로직:
    - 임의의 노드에서 가장 먼 노드를 찾는다.
    - 해당 노드에서 다시 가장 먼 노드까지의 거리를 구한다.
    - BFS를 두 번 사용하면 트리의 지름을 구할 수 있다.

 2. 선택 근거:
    - 트리는 두 노드 사이의 경로가 하나이므로 BFS로 거리를 구할 수 있다.
    - 시간복잡도: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> weight;

int maxNode = 1;
int maxDist = 0;

void bfs(int start, int n){
    queue<int> que;
    vector<int> visited(n+1,0);
    vector<int> dist(n+1,0);

    que.push(start);
    visited[start] = 1;

    maxDist = 0;

    while(!que.empty()){
        int cur = que.front();
        que.pop();

        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];

            if(visited[next]) continue;

            visited[next] = 1;
            dist[next] = dist[cur] + weight[cur][i];
            que.push(next);

            if(dist[next] > maxDist){
                maxDist = dist[next];
                maxNode = next;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    graph.resize(n+1);
    weight.resize(n+1);

    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin >> a >> b >> w;

        graph[a].push_back(b);
        weight[a].push_back(w);

        graph[b].push_back(a);
        weight[b].push_back(w);
    }

    bfs(1,n);
    bfs(maxNode,n);

    cout << maxDist;

    return 0;
}