// PGS 86971
// 전력망을 둘로 나누기

#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int matrix[100+2][100+2];
bool vis[100 + 2];

// 1. 핵심 로직: 인접 행렬과 BFS를 이용하여 연결된 간선을 전부 한번씩 끊어보는 완전탐색을 진행  
// 2. 선정 이유: 완전탐색을 제외하고는 떠오르는 알고리즘이 없어서 진행했습니다.
// 인접 행렬을 쓴 이유: 간선을 끊는 과정을 단순한 로직 및 O(1)의 시간복잡도로 진행하기 위해서
// 시간복잡도: O(N^2)

int BFS(int v1, int n)
{
    int cnt1 = 0;
    queue<int> q;
    q.push(v1);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        vis[cur] = true;
        cnt1++;
        for(int i = 1; i <= n; i++)
            if(matrix[cur][i] && !vis[i])
            { 
                vis[i] = true;
                q.push(i);
            }
    }
    for(int i = 1; i <= n; i++) vis[i] = false;
    return abs(cnt1 - (n - cnt1));
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999;
    //인접 행렬 만들기
    int v1, v2;
    
    for(int i = 0; i < wires.size(); i++)
    {
        v1 = wires[i][0];
        v2 = wires[i][1];
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }
    //인접 행렬 세팅 완료
    //전선을 하나씩 끊어가며 BFS
    for(int i = 0; i < wires.size(); i++)
    {
        v1 = wires[i][0];
        v2 = wires[i][1];
        matrix[v1][v2] = 0;
        matrix[v2][v1] = 0;
        int temp = BFS(v1, n);
        if(answer > temp) answer = temp;
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }
    return answer;
}