#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[101] = { false };
int cnt = 0;
void dfs(vector<vector<int>> wires, int s, int w, int n) { //시작점,w쨰 간선,노드수
    cnt++;

    for (int i = 0;i < n - 1;i++) {
        if (i != w) {
            if (wires[i][0] == s && !visited[wires[i][1]]) {
                visited[wires[i][1]] = true;
                dfs(wires, wires[i][1], w, n);
                visited[wires[i][1]] = false;
            }
            if (wires[i][1] == s && !visited[wires[i][0]]) {
                visited[wires[i][0]] = true;
                dfs(wires, wires[i][0], w, n);
                visited[wires[i][0]] = false;
            }

        }
    }
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 1000000;

    //wires[i][0]을 dfs의 시작점으로 잡고, 몇번쨰 간선인지 dfs에 넘겨줌
    //dfs는 w번째 간선만 제외하고 dfs돌면서 방문한 노드의 개수 센다
    //이걸 모든 간선 n-1개에 대해 dfs
    for (int i = 0;i < n - 1;i++) {
        visited[wires[i][0]] = true;
        dfs(wires, wires[i][0], i, n);
        visited[wires[i][0]] = false;
        answer = min(answer, abs(abs(n - cnt) - cnt));
        cnt = 0;
    }


    return answer;
}