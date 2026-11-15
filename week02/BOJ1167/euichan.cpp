#include <iostream>
#include <string>
#include <vector>
#define MAX_NUM (100000 + 2)

using namespace std;

/*
* 1. 핵심 로직: DFS를 진행하며 거리 값을 더해가다가 그 전 DFS 함수가 리턴되어 그전 노드로 돌아가면 거리 값을 뺀다.
*              최대 거리 값을 저장하고
*
* 2. 선택 근거: 트리를 전부 탐색해보아야 할 것으로 판단되어 DFS를 사용했고, 이전에 돌아갈 때 값을 뺐던 DFS 풀이가 생각이 나서 적용해봄.
*/

/*
1. 첫째 줄에 정점의 개수 V
2. V개의 줄에 각 정점의 간선 정보를 표준 입력으로 받음.
*/

int max_val = 0;
int cnt = 0;
int that_point = 0;
int V;

typedef struct _node
{
    int len;
    int num;
} node_t;

vector<vector<int>> lines;
vector<vector<node_t>> graph;
// vector<int> visited(MAX_NUM);
int visited[MAX_NUM]; // [피드백 반영] 방문 배열은 요소 입출을 하는 것이 아니므로 일반 배열로 변경

void InputData()
{
    cin >> V;
    lines.resize(V);

    for (int i = 0; i < V; i++)
    {
        int num = 0;
        
        while (cin >> num)
        {
            lines[i].push_back(num);
            if (num == -1) break;
        }
    }
}

void MakeGraph(void)
{
    graph.resize(V + 1);

    for (int i = 0; i < lines.size(); i++)
    {
        int node = lines[i][0];
        
        for (int j = 1; lines[i][j] != -1; j = j + 2)
        {
            graph[node].push_back((node_t){lines[i][j+1], lines[i][j]});
        }
    }
}

void Dfs(vector<vector<node_t>> &g, int n)
{
    if (visited[n]) return;
    if (cnt > max_val)
    {
        max_val = cnt;
        that_point = n;
    }
    
    visited[n] = 1;

    for (int i = 0; i < g[n].size(); i++)
    {
        cnt += g[n][i].len;
        Dfs(g, g[n][i].num);
        cnt -= g[n][i].len;
    }
}

int main(void)
{
    // freopen("test_case.txt", "r", stdin);
    InputData();
    MakeGraph();

    // for (int i = 1; i <= V; i++)
    // {
    //     std::fill(visited.begin(), visited.end(), 0); // 방문 벡터 초기화하는 것을 깜빡함..
    //     cnt = 0;
    //     Dfs(graph, i);
    // }

    // 위의 코드처럼 하면 시간 초과됨.
        
    Dfs(graph, 1);
    cnt = 0;
    // visited.assign(V + 1, 0);
    memset(visited, 0, sizeof(int) * (V + 1)); // [피드백 반영] memset으로 초기화
    Dfs(graph, that_point);
    cout << max_val;

    return 0;
}
