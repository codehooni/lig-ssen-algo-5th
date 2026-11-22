// JOL1733
// 오목

#include <string>
#include <vector>
using namespace std;

/*
1. 핵심 로직
- 가설 1
검/흰돌 지점에서 인접한 검/흰돌을 전부 방문처리 후 DFS.
이때 방문처리와 동시에 방향값도 인자로 넘겨준다. 방향은 8방향.
탐색해왔던 방향과 다른 방향의 검/흰돌이 인접해있을 경우 쌓은 누적합을 초기화하고 해당 방향으로 탐색 시작
리턴값: bool(이겼으면 true)
매개변수: (int 현재 행, int 현재 열, int 누적 돌 수, char 돌 색, int 방향)

-> 구현을 고민하다 1시간이 넘어서 클로드가 짜준 정답보고 학습중입니다.
        
*/

const int N = 19;

// 4방향만 확인: →, ↓, ↘, ↗  (dr: 행 변화, dc: 열 변화)
const int dr[4] = { 0, 1, 1, -1 };
const int dc[4] = { 1, 0, 1,  1 };

// 보드 범위 안인지 검사 (범위 밖 접근은 정의되지 않은 동작이므로 필수)
bool inRange(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < N;
}

// 승부가 났으면 {색, 행, 열}, 아니면 {0} 반환 (행/열은 1부터 시작)
vector<int> solution(vector<vector<int>> board) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int color = board[r][c];
            if (color == 0) continue;              // 빈칸은 건너뜀

            for (int d = 0; d < 4; d++) {
                // 이 방향의 "바로 이전 칸"이 같은 색이면 시작점이 아님
                int pr = r - dr[d], pc = c - dc[d];
                if (inRange(pr, pc) && board[pr][pc] == color) continue;

                // 시작점이므로 같은 색이 몇 개 이어지는지 센다
                int cnt = 1;
                int nr = r + dr[d], nc = c + dc[d];
                while (inRange(nr, nc) && board[nr][nc] == color) {
                    cnt++;
                    nr += dr[d];
                    nc += dc[d];
                }

                // 정확히 5개일 때만 승리 (6목 이상은 제외)
                if (cnt == 5) return { color, r + 1, c + 1 };
            }
        }
    }
    return { 0 };   // 승부 미결정
}
