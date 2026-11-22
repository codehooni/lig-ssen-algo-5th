#include <iostream>
using namespace std;
/*
핵심로직 : 바둑판의 모든 칸을 왼쪽 열부터, 같은 열이면 위쪽 행부터 확인합니다.
            돌이 있는 칸에서 가로, 세로, 두 대각선 4방향으로 같은 색이 몇 개 이어지는지 셉니다.
            이전 칸이 같은 색이면 줄의 중간이라 건너뛰고, 줄의 시작점에서만 셉니다.
            정확히 5개일 때만 승리로 보고 색과 시작점 좌표(가장 왼쪽 돌)를 반환합니다.
            끝까지 못 찾으면 0을 반환합니다.
사용근거 : 19*19라서 완전탐색으로 된다고 하더라구요..
            근데 도는거보다 5개 연속된거 확인하는걸 못짜겠었습니다..
시간복잡도 : O(n^2)

AI사용: 도저히 로직이 안짜져서 AI를 사용해 답지 보면서 학습했습니다.

*/


int board[19][19];
// 시작점이 항상 가장 왼쪽(같은 열이면 가장 위)이 되도록 잡은 방향
int dr[4] = {0, 1, 1, -1};
int dc[4] = {1, 0, 1, 1};

bool inRange(int r, int c) {
    return r >= 0 && r < 19 && c >= 0 && c < 19;
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];

    // 열 먼저, 그다음 행 순서로 탐색해서 가장 왼쪽(위) 돌을 먼저 찾음
    for (int c = 0; c < 19; c++) {
        for (int r = 0; r < 19; r++) {
            int color = board[r][c];
            if (color == 0) continue;

            for (int d = 0; d < 4; d++) {
                // 이전 칸이 같은 색이면 시작점이 아님
                int pr = r - dr[d], pc = c - dc[d];
                if (inRange(pr, pc) && board[pr][pc] == color) continue;

                // 같은 색이 몇 개 이어지는지 센다
                int cnt = 0;
                int nr = r, nc = c;
                while (inRange(nr, nc) && board[nr][nc] == color) {
                    cnt++;
                    nr += dr[d];
                    nc += dc[d];
                }

                if (cnt == 5) {
                    cout << color << "\n";
                    cout << r + 1 << " " << c + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}