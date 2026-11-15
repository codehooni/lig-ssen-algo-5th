// BOJ 1167
// 트리의 지름

#include <vector>
#define Vertex first
#define Dist second
using namespace std;

// 1. 핵심 로직: 인접 리스트와 DFS를 이용하고
//              임의의 한 점에서 DFS를 하고 제일 먼 정점을 구한 다음
//              다시 그 정점에서 제일 먼 정점을 구하면 그것이 트리의 지름이 됨.
// 2. 선정 이유: 인접 행렬로 구현하게 되면 메모리가 부족하여 인접 리스트로 구현
//              DFS를 이용하면 제일 먼 정점을 구하기에 최적하다고 생각함.

// 미완성된 코드입니다. 
// AI로는 '임의의 한 점에서 DFS하고 제일 먼 정점을 구한 다음
// 다시 그 정점에서 제일 먼 정점을 구하면 그것이 트리의 지름이 됨' 이 핵심 로직이라는 것을 보고
// 그 뒤로는 제가 직접 재귀로 DFS 구현, DFS 도중 제일 먼 정점을 구하는 로직 집어넣기를 했습니다.
// 제일 먼 정점을 구하는 로직을 구현하다가 뇌가 뻗었습니다.

vector<pair<int, int>> list[100000 + 1];
bool vis[100000 + 1];
int max_val, max_vertex;

int DFS(int start, int pre)
{
    int max_val = pre;
    vis[start] = true;
    for(auto iter = list[start].begin(); iter != list[start].end(); iter++)
    {
        if(vis[(*iter).Vertex]) continue;
        int temp = DFS((*iter).Vertex, pre + (*iter).Dist);
        if(max_val < temp) 
        {
            max_vertex = (*iter).Vertex;
            max_val = temp;
        }
    }
    return max_val;
}

int solution(int V, vector<vector<int>> lines) {
    // 여기에 코드를 작성하세요.
    int answer = 0;
    // 인접 리스트 세팅
    for(int i = 0; i < lines.size(); i++)
    {
        for(int j = 1; lines[i][j] != -1; j++)
        {
            int temp1, temp2;
            if(j & 1) temp1 = lines[i][j]; // 정점 데이터 갱신
            else 
            // 간선 가중치 데이터 갱신 및 인접 리스트에 추가
            {
                temp2 = lines[i][j];
                list[lines[i][0]].push_back({temp1, temp2});
            }
        }
    }
    // 인접 리스트 세팅 완료
    answer = DFS(lines[1][0], 0);
    //answer = DFS(max_vertex, 0);
    return max_vertex;
}
