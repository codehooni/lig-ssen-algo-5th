#include <string>
#include <vector>
#define BIG_NUM 10000

/*
* 1. 핵심 로직: 주어진 벡터를 그래프의 형태로 만들고, DFS를 통해 각 노드에 연결되어있는 요소의 수(a)+1를 벡터에 담습니다. (자기 자신 포함)
*              이후, abs(n - 2*(a+1))의 최소값을 구합니다.
*
* 2. 선택 근거: 예시가 트리의 형태로 주어졌으므로 완전 탐색으로 각 노드에 연결된 개수를 구할 수 있을 거라고 생각했습니다.
*              BFS로도 가능하지만, 자기 자신과 연결된 요소를 탐색한다는 컨셉이 DFS와 더 잘 맞다고 생각했습니다.
*/

/*
1. 송전탑이 트리 형태로
2. 하나를 끊어서 분할?
3. 송전탑의 개수를 최대한 비슷하게
4. 송전탑 개수 차이 return

노드 별로 달려있는 노드의 개수를 저장하는 편이 나을 것 같음.
DFS로 각 노드에 달려있는 노드 추가 -> 깊이가 중요하므로?
전체 노드의 개수(n)에서 한 노드에 달려있는 노드의 수(a)를 확인했을 떄,
abs(n - 2 * (a+1))가 최소가 되도록 노드 별로 탐사
*/

using namespace std;

void MakeGraph(vector<vector<int>> &g, vector<vector<int>> &w)
{
    for (int i = 0; i < w.size(); i++)
    {
        g[w[i][0]].push_back(w[i][1]);
        g[w[i][1]].push_back(w[i][0]);
    }
}

void Dfs(vector<vector<int>> &g, vector<int> &v, int num)
{   
    v[num] = 1;
    
    for (int i = 0; i < g[num].size(); i++)
    {
        if (v[g[num][i]]) continue;
        Dfs(g, v, g[num][i]);
        v[num] += v[g[num][i]];
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);
    
    MakeGraph(graph, wires);
    
    Dfs(graph, visited, 1);
    
    int min = BIG_NUM;
    
    for (int i = 2; i <= n; i++)
    {
        int temp = abs(n - 2 * visited[i]);
        min = min > temp ? temp : min; 
    }
    
    return answer = min;
}