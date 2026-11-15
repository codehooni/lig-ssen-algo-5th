#include <string>
#include <vector>
#include <cstring>

using namespace std;
//(AI 활용)
//1. 핵심 로직: 트리에서는 아무 정점에서 가장 먼 정점이 반드시 지름의 한쪽 끝이다.
//              그래서 1번에서 DFS로 가장 먼 정점 A를 찾고, A에서 다시 DFS로 가장 먼 거리를 구하면 그게 지름이다.
//              DFS는 (지금 정점, 출발점에서 여기까지 온 거리)를 들고 깊이 들어가면서, 가장 먼 정점과 거리를 갱신한다.
//              트리는 두 정점 사이 길이 하나뿐이라, 처음 도착했을 때의 거리가 곧 그 정점까지의 거리다.
//2. 선택 근거: 정점이 최대 100,000개라 모든 정점에서 탐색하면 시간 초과가 나서, 탐색 두 번으로 끝내는 방법을 썼다.
//              정점이 많아 2차원 배열로는 메모리가 부족해서, 실제로 연결된 것만 담는 vector<pair> 목록을 썼다.

#define MAX_N (100000+2)       
int N;                         // 이번 문제의 정점 개수
vector<pair<int, int>> graph[MAX_N];   // graph[a] = {(연결된 정점, 거리)}
int visited[MAX_N];            // 1 이면 이미 방문한 정점
int farNode;                   // 지금까지 찾은 가장 먼 정점
int farCost;                   // 그 정점까지의 거리

// lines를 graph(연결 목록)로 옮긴다
void input_data(vector<vector<int>>& lines) {
	for (int i = 1; i <= N; ++i) graph[i].clear();   // 전역 변수라 지난 테스트 값이 남아 있으므로 비운다
	for (int i = 0; i < (int)lines.size(); ++i) {
		int a = lines[i][0];                          // 줄 맨 앞 = 이 줄의 정점
		for (int j = 1; lines[i][j] != -1; j += 2) {  // (정점, 거리)가 두 칸씩 짝, -1이 나오면 끝
			int b = lines[i][j];                      // 연결된 정점
			int w = lines[i][j + 1];                  // 그 정점까지의 거리
			graph[a].push_back({ b, w });             // 반대 방향(b → a)은 b의 줄에 따로 들어 있으므로 한쪽만 넣는다
		}
	}
}

// DFS를 새로 시작하기 전에 방문 기록과 가장 먼 정점 기록을 지운다
void initDFS(void) {
	memset(visited, 0, sizeof(visited));  
	farNode = 1;
	farCost = 0;
}

// 탐색하면서 가장 먼 정점과 거리를 farNode, farCost에 기록한다
void tree_DFS(int curr, int cost) {
	visited[curr] = 1;                    

	if (cost > farCost) {                 
		farCost = cost;                    // 가장 먼 거리 갱신
		farNode = curr;                    // 가장 먼 정점 갱신
	}

	for (int i = 0; i < (int)graph[curr].size(); ++i) {   
		int next = graph[curr][i].first;   // 연결된 정점
		int w = graph[curr][i].second;     // 그 정점까지의 거리
		if (visited[next]) continue;       
		tree_DFS(next, cost + w);        
	}
}

int solution(int V, vector<vector<int>> lines) {
	N = V;                     
	input_data(lines);         

	initDFS();
	tree_DFS(1, 0);            // 1번에서 출발 → 가장 먼 정점 찾기
	int A = farNode;         

	initDFS();                 
	tree_DFS(A, 0);            // A에서 출발 → 가장 먼 거리 찾기
	return farCost;            
}
