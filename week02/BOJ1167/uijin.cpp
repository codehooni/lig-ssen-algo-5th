#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

// 알고리즘 선택 이유 : 정점 수가 최대 100,000개이므로 인접 행렬 대신 인접 리스트 사용.
// 핵심 로직 : 임의의 정점에서 BFS로 가장 먼 정점 A를 탐색하고, A에서 BFS를 수행하여 정점 B를 탐색.
//				A와 B사이 경로의 누적 가중치가 트리의 지름이 된다.
// 시간 복잡도 : O(N)

#define MAX_N 100000
int N;
int Queue[MAX_N + 2] = { 0 };
long long visited[MAX_N + 2] = { 0 };

struct Edge{
int node;
long long weight;
};
vector<Edge> arr[MAX_N+2];

// 정점별 인접 정점과 간선 가중치를 입력받아 인접 리스트 구성.
void InputToList() {
	scanf("%d",&N);

	for (int i = 1;i < N + 1;i++) {
		int each_line, a, b;
		scanf("%d",&each_line);

		while (1) {
			scanf("%d", &a);
			if (a == -1) { break; }
			scanf("%d", &b);

			arr[each_line].push_back({a,b});
		}
	}
}

// 시작점에서 가장 먼 정점을 BFS로 탐색하고, 정점 번호와 누적 가중치를 반환.
Edge WeightSearchBFS(const vector<Edge> arr[], int start) {
	fill(visited, visited + MAX_N + 2, 0);
	int front= 0;
	int rear = 0;

	int Best_node = start;
	long long Best_weight = 0;

	Queue[rear++] = start;
	visited[start] = 0;

	while (front!=rear) {
		int curr = Queue[front++];

		for (int i = 0; i < (int)arr[curr].size(); i++) {
			int next = arr[curr][i].node;
			long long weight = arr[curr][i].weight;

			if (next != start && visited[next] == 0) {
				visited[next] = visited[curr] + weight;
				Queue[rear++] = next;
			}
		}

		if (visited[curr] >Best_weight) {
			Best_weight = visited[curr];
			Best_node = curr;
		}
	}

	return {Best_node,Best_weight};
}

int main(void) {
	InputToList();

	Edge e1=WeightSearchBFS(arr, 1);
	Edge e2=WeightSearchBFS(arr, e1.node);
	printf("%lld\n", e2.weight);
	return 0;
}
#endif