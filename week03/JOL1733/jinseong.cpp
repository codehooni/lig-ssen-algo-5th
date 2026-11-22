#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
    시간 복잡도: O(N^2)
    접근 방식: 바둑알을 카운팅할 구조체를 만들고 행, 열, 대각선별로 비교하며 오목인지 확인.
    선택 근거: 각 행, 열, 대각선별로 바둑알 누적수를 확인하기 위해 구조체 배열 활용.
    핵심 로직:
        1. 전체 바둑판을 순회하며 각 행, 열, 대각선에 다음 조건을 고려하며 바둑알 카운팅
            a. 이전과 동일한 색이면 카운트 1 증가
            b. 색이 다르고 이전 카운트가 5개가 아니면 새로운 바둑알로 초기화
        2. 승자가 결정나면 가장 왼쪽 좌표로 조정하고 승자 정보를 받아와 출력
        3. 승자가 없으면 '0' 출력
*/

#define N 19

typedef struct _omok {
    int y;
    int x;
    int cnt;
    char color;
} omok;

char board[N + 2][N + 2];
omok rw[N + 2];
omok cl[N + 2];
omok dr[2 * N + 2];
omok dl[2 * N + 2];
omok* win;

void input_board() 
{
    string line;

    for (int i = 1; i <= N; i++) {
        getline(cin, line);
        stringstream ss(line);
        char num, j = 1;
        while (ss >> num) board[i][j++] = num;
    }
}

int toIdx(omok *omk, int r, int c) {
    if (omk == rw) return r;
    if (omk == cl) return c;
    if (omk == dr) return r + c;
    if (omk == dl) return N + r - c;
    return -1;
}

bool checkWin(omok *omk, int r, int c) {
    int idx = toIdx(omk, r, c);
    char v = board[r][c];
    omok &o = omk[idx];

    if (o.color == v) {
        o.cnt += 1;
        return false;
    }

    if (o.cnt != 5 || o.color == '0') {
        o = (omok){ r, c, 1, v };
        return false;
    }

    // 가장 왼쪽 좌표로 변환(우대각선)
    if (o.x > c) {
        o.y = r - 1;
        o.x = c + 1;
    }

    win = omk + idx;
    return true;
}

void solution() {
    for (int r = 1; r <= N + 1; r++) {
        for (int c = 1; c <= N + 1; c++) {
            if (checkWin(rw, r, c) ||
                checkWin(cl, r, c) ||
                checkWin(dr, r, c) ||
                checkWin(dl, r, c)
            ) {
                cout << win->color << endl;
                cout << win->y << " " << win->x << endl;
                return;
            }
        }
    }

    cout << "0" << endl;
}

int main(void) {
    input_board();
    solution();
    return 0;
}