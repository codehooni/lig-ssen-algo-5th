#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    시간 복잡도: O(N * M * K) (최악의 경우 K개의 맵을 한번씩 방문한다고 가정)
    접근 방식: 큐 입력 순서가 특정 지점 방문 상태에 영향을 주지 않도록 재밍 장비 사용 횟수별로 맵을 나누어 BFS 진행
    선택 근거: 동등한 가중치를 지닌 그래프에서 목표 지점까지 최단 거리를 구하기 위해 BFS 사용
    핵심 로직
        1. BFS로 인접한 지점 탐색
        2. 재밍 장비 사용 횟수에 따라 방문 배열을 나누어 누적 거리 기록
        3. 목표 지점 도달 시 거리 반환 / 도달 불가 시 -1 반환
*/

#define MAX_N 100
#define MAX_M 100ㄴ
#define MAX_K 10

typedef struct _Drone {
    int y;
    int x;
    int k;
} Drone;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

bool isOutside(int y, int x, int outY, int outX) {
    return y < 0 || y >= outY || x < 0 || x >= outX; 
}

int bfs(vector<string>& field, int k) {
    int n = field.size(), m = field[0].size();
    int visited[MAX_N][MAX_M][MAX_K + 1] = { 0, };
    queue<Drone> q;
    Drone end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cur = field[i][j];
            if (cur == 'S') {
                q.push({ i, j, 0 });
                visited[i][j][0] = 1;
            }
            else if (cur == 'E') end = { i, j };
        }
    }

    while (!q.empty()) {
        Drone curr = q.front();
        q.pop();
        int cy = curr.y;
        int cx = curr.x;
        int ck = curr.k;

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (isOutside(ny, nx, n, m) || field[ny][nx] == '#') continue;
            
            int nk = field[ny][nx] == 'R' ? ck + 1 : ck;
            if (nk > k || visited[ny][nx][nk]) continue;
            if (ny == end.y && nx == end.x) return visited[cy][cx][ck]; // 시작점을 카운트하지 않으므로 이전값 반환
            visited[ny][nx][nk] = visited[cy][cx][ck] + 1;
            q.push({ ny, nx, nk });
        }
    }

    return -1;
}

int solution(vector<string> field, int k) {
    return bfs(field, k);
}