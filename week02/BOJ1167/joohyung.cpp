#include <string>
#include <vector>
using namespace std;
#define MAX_N (10000+2)

/**
 * 1. 핵심 로직: DFS를 활용 (미해결 AI 도움 받음) 
 * 2. 선택 근거: DFS의 시작점을 임의로 주더라도 해당 지점과 가장 먼 거리의 있는 점은 Leaf임 그 Leaf node를 시작점으로 해서 최대 거리를 구하면 트리의 지름을 구할 수 있음
 */

vector<pair<int,int>> adj[MAX_N];
bool visited[MAX_N] = {false,};
int selected; 
int dist = 0; 

void DFS(int start,int cnt) {
    if (cnt > dist) 
    {
        dist = cnt;
        selected = start;
    }

    for (int i=0;i<adj[start].size();i++){
        int to = adj[start][i].first;
        int weight = adj[start][i].second;
        if (!visited[to]) {
            visited[to]=true;
            cnt+=weight;
            DFS(to,cnt);
            cnt-=weight;
            visited[to]=false;
        }
    }
}

int solution(int V, vector<vector<int>> lines) {
    // 여기에 코드를 작성하세요.

    for (int i=0;i<V;i++){
        int to=lines[i][0];
        for (int j=1;;j+=2)
        {
            if (lines[i][j]==-1) break;

            int from =lines[i][j];
            int weight = lines[i][j+1];
            adj[to].push_back({from,weight});
        }
    }

    // 
    DFS(1,0);
    dist=0;
    fill(visited,visited+MAX_N,false);
    visited[selected]=true;
    DFS(selected,0);
    return dist;
}