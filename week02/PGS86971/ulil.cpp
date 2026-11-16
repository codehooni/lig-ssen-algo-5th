#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

//1. 핵심 로직: 전선을 하나씩 끊어 보면서, 끊은 전선의 한쪽 끝에서 BFS로 갈 수 있는 송전탑 개수를 센다.
//              반대쪽 개수는 전체 N에서 빼서 구하고, 두 덩어리 차이 중 가장 작은 값을 정답으로 한다.
//              전선은 arr에서 0으로 바꿔 끊고, BFS가 끝나면 다시 1로 바꿔 다음 전선을 시도한다.
//              visited로 이미 방문한 송전탑은 다시 세지 않는다.
//2. 선택 근거: 어느 전선을 끊어야 할지 미리 알 수 없지만, 송전탑이 최대 100개라 전선을 전부 끊어 봐도 충분히 빠르다.
//              끊었을 때 이어진 송전탑을 빠짐없이 세야 해서, 연결된 곳을 차례로 방문하는 BFS를 썼다.
//              송전탑이 최대 100개라 연결 정보를 2차원 배열(arr)로 저장해도 메모리가 충분하다.

#define MAX_N (100+2)
int N;
int arr[MAX_N][MAX_N];   // arr[a][b] = 1 이면 a번과 b번 송전탑이 전선으로 연결됨
int visited[MAX_N];      // 1 이면 이미 방문한 송전탑
int Queue[MAX_N];        
int front, rear;

void input_data(vector<vector<int>>& wires) {
	memset(arr, 0, sizeof(arr));   // 전역 배열이 남아 있으므로 초기화
	for (int i = 0; i < (int)wires.size(); ++i) {
		int a = wires[i][0]; //처음 숫자들을 어떻게 나열할지 생각이 안났음(AI 활용)
		int b = wires[i][1];
		arr[a][b] = 1;             // 전선은 방향이 없으므로 양쪽 다 표시
		arr[b][a] = 1;
	}
}

void initQueue(int start) {
	front = rear = 0;
	memset(visited, 0, sizeof(visited));
	Queue[rear++] = start;
	visited[start] = 1;
}

int power_BFS(int start) {
	int curr, cnt = 1;
	initQueue(start);
	while (front != rear) {
		curr = Queue[front++];
		for (int next = 1; next <= N; ++next) {
			if (arr[curr][next] == 0) continue;   // 연결 안 됨 (끊은 전선 포함)
			if (visited[next]) continue;          // 이미 방문
			visited[next] = 1;
			Queue[rear++] = next;
			cnt++;
		}
	}
	return cnt;
}

int solution(int n, vector<vector<int>> wires) {
	N = n;
	input_data(wires);

	int answer = N;
	for (int i = 0; i < (int)wires.size(); ++i) {
		int a = wires[i][0];
		int b = wires[i][1];

		arr[a][b] = arr[b][a] = 0;        // 전선 끊기
		int cnt = power_BFS(a);         
		int diff = abs(cnt - (N - cnt)); 
		if (diff < answer) answer = diff;
		arr[a][b] = arr[b][a] = 1;        // 다음 전선을 위해 다시 연결
	}
	return answer;
}
