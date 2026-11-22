#include <bits/stdc++.h>
using namespace std;

//AI 설명 참고: 처음에는 흑과 백의 행,열, 좌대각, 우대각의 경우를 
//배열에 저장하고 승자를 찾는 방식으로 진행했으나
//배열의 개수가 많아지고 승자의 가장 왼쪽 돌의 위치를 구하는 방법이 복잡해졌다.

//내 이해: 시작점을 찾고 시작점으로부터 정확히 같은 색의 돌이 5개 연속되는지만
//확인함으로써 쓸데없는 배열의 개수를 줄이고 더 직관적인 방식으로 승자를 찾을 수 있다.

int board[21][21];

// 오른쪽, 아래, 오른쪽 아래, 오른쪽 위, 시작점 여부를 확인하기 위한 방향벡터
int dr[4] = {0, 1, 1, -1};
int dc[4] = {1, 0, 1, 1};

// 바둑판 범위 확인
bool inRange(int r, int c) {
    return r >= 1 && r <= 19 && c >= 1 && c <= 19;
}

int main() {
    // 입력
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            cin >> board[i][j];
        }
    }

    // 모든 좌표 검사
    for (int c = 1; c <= 19; c++) {
        for (int r = 1; r <= 19; r++) {
            int color = board[r][c];
            if (color == 0) continue;

            //  방향 검사
            for (int d = 0; d < 4; d++) {

                int prevR = r - dr[d];
                int prevC = c - dc[d];

                // 앞에 같은 색이 있으면 시작점이 아님
                if (inRange(prevR, prevC) && board[prevR][prevC] == color) {
                    continue;
                }

                bool five = true;

                // 현재 돌을 포함해 5개 확인
                for (int k = 1; k < 5; k++) {
                    int nr = r + dr[d] * k;
                    int nc = c + dc[d] * k;

                    if (!inRange(nr, nc) ||  board[nr][nc] != color) {
                        five = false;
                        break;
                    }
                }

                if (!five) continue;

                // 여섯 번째 돌 확인
                int nextR = r + dr[d] * 5;
                int nextC = c + dc[d] * 5;

                if (inRange(nextR, nextC) && board[nextR][nextC] == color) {
                    continue;
                }

                // 정확히 5개이면 승리
                cout << color << '\n';
                cout << r << " " << c << '\n';

                return 0;
            }
        }
    }

    // 승자가 없는경우
    cout << 0 << '\n';

    return 0;
}