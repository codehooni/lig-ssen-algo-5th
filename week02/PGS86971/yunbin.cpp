/*
 1. 핵심 로직:
    - 주어진 wires를 이용해 무방향 그래프를 구성한다.
    - 전선을 하나씩 끊었다고 가정하고 BFS로 연결된 노드 수를 구한다.
    - 전체 노드 수에서 방문한 노드 수를 빼면 반대쪽 노드 수를 알 수 있다.
    - 두 노드 수의 차를 절댓값으로 구하고 최솟값을 선택한다.

 2. 선택 근거:
    - 처음에는 왼쪽과 오른쪽 큐를 각각 사용했지만, 한쪽만 탐색해도
      반대쪽 노드 수를 구할 수 있어 BFS를 개선했다.
    - 모든 전선을 하나씩 끊어보므로 시간복잡도는 O(n²)이다.
    - 모두 연결된 노드이고 가중치가 없기 때문에 bfs를 사용하기 적합하다.
    - 노드의 연결을 입력으로 끊어야할 지점을 찾기 수월했다.
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

int answer = 101; // 노드 수의 차가 100을 넘지 않으므로
unordered_map<int,vector<int>> graph; // 노드의 연결 정보를 담은 그래프

void init(vector<vector<int>> wires){
    for(auto& num : wires){
        graph[num[0]].push_back(num[1]);
        // 무방향 그래프이므로 양쪽에 대입
        graph[num[1]].push_back(num[0]);
    }
}

// 개선한 BFS
void bfs(vector<vector<int>> wires,int n){
    for(auto& num : wires){
        queue<int> que;
        int nodeCount=1;
        que.push(num[0]);

        vector<int> visited(n+1,0);
        visited[num[0]] =1;

        while(!que.empty()){
            int index =que.front();que.pop();
            vector<int> connectedNodes = graph[index];

            for(int i : connectedNodes){
                // 현재 끊은 전선은 탐색하지 않는다.
                if((index==num[0] && i==num[1]) ||
                    (i==num[0] && index==num[1] || visited[i])) continue;

                visited[i]=1;
                nodeCount++;
                que.push(i);
            }
        }

        answer = min(answer, abs(nodeCount - (n - nodeCount)));
    }
}

int solution(int n, vector<vector<int>> wires) {
    init(wires);
    bfs(wires,n);
    return answer;
}