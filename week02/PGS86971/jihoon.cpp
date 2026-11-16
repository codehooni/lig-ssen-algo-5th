/*

0. 선택근거:
- 모든 선을 끊고 모든 노드를 확인해도 시간 복잡도가 넘지 않아서 된다고 판단하였다.

1. 아이디어:
모든 전선을 끊어보고 최소 송전탑의 갯수 차이를 구한다.
- 모든 전선을 벡터에 담는다.
- for 각 전선을 끊기
    - BFS를 통해서 각각 몇 개의 송전탑이 연결되어 있는지 확인한다.
    - 가장 적은 차이를 가진 것을 답으로 기억한다.

2. 시간복잡도:
- O(N^2) < 10,000

3. 자료구조:
- edge: vector
*/

#include <string>
#include <vector>
#include <queue>
#define MAX_N (100 + 1)

using namespace std;

bool visited[MAX_N];
int cnt;
vector<vector<int>> edge(MAX_N, vector<int>());
pair<int, int> no;

void bfs(int node);

int solution(int n, vector<vector<int>> wires) {
    
    for(auto& w: wires) {
        edge[w[0]].push_back(w[1]);
        edge[w[1]].push_back(w[0]);
    }
    
    int ans = n;
    for(auto& w: wires) {
        no = {w[0], w[1]};
        fill(visited, visited + MAX_N, false);
        cnt = 0;
        bfs(1);
        ans = min(ans, abs(n - 2 * cnt));
    }
        
    return ans;
}

void bfs(int node) {
    visited[node] = true;
    cnt++;
    
    queue<int> q;
    q.push(node);
    
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        
        for(auto& next : edge[curr]) {
            if((no.first == curr && no.second == next) || (no.first == next && no.second == curr)) continue;
            if(visited[next]) continue;
            
            visited[next] = true;
            q.push(next);
            cnt++;
        }
        
    }
}