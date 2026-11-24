/* Test1-1 정찰 드론의 레이더 돌파

본 코드는 클로드가 생성한 코드입니다.
본래 짰던 코드의
1. 핵심 로직: 거리를 측정하는 BFS를 짜놓고, 큐에서 지점을 하나 꺼낼 때 R이면 k--;을 수행하고 k가 0이면
                R을 큐에 담지 않도록 설정하는 로직을 추가
2. 선정 이유: 탐색 시에 R을 지날 때마다 k를 감소시키면 그냥 되는줄..
-> 이렇게 로직을 돌려보다가 뭔가 이상했습니다!!
거리를 담는 2차원 int 배열 board를 전역으로 설정해놓으니 테스트케이스 1을 마치고 테스트케이스 2에
그대로 적용되는 것이었습니다!! 버그인줄 알고 복기하는 시간에 의찬씨께 질문했으나 버그가 아니었습니다...
그래서 board를 solution 함수 호출할 때마다 전체를 -1로 초기화해줬더니 모의코테 칠때 17점->50점으로 올랐습니다.

그러나 클로드 돌려보니 나머지 50점은 핵심 로직을 아예 바꿔야 했습니다.
바꾼 코드의
1. 핵심 로직: 큐에 집어넣는 자료형을 {행, 열, 지금까지 쓴 재밍 횟수, 누적 거리}로 하고,
                방문표시를 하는 배열(벡터)를 2차원이 아닌 지금까지 재밍을 쓴 횟수를 추가한
                3차원 벡터로 설정하여 자료구조를 만듭니다.
                그러고 탐색할 때 인접한 칸이 R인데 지금까지 재밍을 쓴 횟수를 넘는다면
                큐에 넣지 않고, 횟수가 아직 남았지만 방문한 칸이면 큐에 집어넣지 않도록 하는 로직입니다.
2. 선정 이유: 클로드왈 탐색할 때 k를 어느 한 타이밍에 감소시키는 로직으론 절대 풀 수 없다고 합니다.
*/

#include <string>
#include <vector>
#include <queue>
using namespace std;

// 큐에 들어가는 BFS 상태 (C++ 기준: struct도 멤버 함수/생성자를 가질 수 있음)
struct State {
    int r, c;      // 현재 위치
    int used;      // 지금까지 쓴 재밍 횟수
    int dist;      // 지금까지 이동 횟수
};

const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, 1, -1 };

int solution(vector<string> field, int k) {
    int n = field.size();
    int m = field[0].size();

    // 방문 체크: visited[r][c][used]
    vector<vector<vector<bool>>> visited(
        n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
    //(소신발언)근데 이정도 벡터를 선언할 정도면 코테에 안 나오지 않을까요?

    queue<State> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (field[i][j] == 'S') {
                visited[i][j][0] = true;
                q.push({i, j, 0, 0});
            }

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        if (field[cur.r][cur.c] == 'E') return cur.dist;

        for (int d = 0; d < 4; d++) {
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (field[nr][nc] == '#') continue;

            int nused = cur.used + (field[nr][nc] == 'R' ? 1 : 0);
            if (nused > k) continue;
            if (visited[nr][nc][nused]) continue;

            visited[nr][nc][nused] = true;
            q.push({nr, nc, nused, cur.dist + 1});
        }
    }
    return -1;
}