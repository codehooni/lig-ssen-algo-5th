/*

0. 선택근거
- bruteforce로도 충분한 시간 복잡도가 나온다.

1. 아이디어
- 19x19를 순회한다.
- 해당 위치에서 8방향을 확인한다. 
- 5개일 경우 승리자를 반환한다.

2. 시간복잡도
- O(NDK) : N ⩽ 361, D ⩽ 8, K ⩽ 5

3. 자료구조
- board: 2D int

*/


#include <iostream>
using namespace std;

typedef struct {
    int r;
    int c;
}DIR;

int board[21][21];

DIR D[4] = { {0, 1}, {1, 0}, {1, 1}, {-1, 1} };

bool inRange(int r, int c) {
    return 1 <= r && r <= 19 && 1 <= c && c <= 19;
}

int main() {

    for(int i = 1; i <= 19; i++)
        for(int j = 1; j <= 19; j++)
            cin >> board[i][j];

    for(int i = 1; i <= 19; i++) {
        for(int j = 1; j <= 19; j++) {
            int me = board[i][j];
            if(me == 0) continue;

            for(auto& d : D) {
                int pr = i - d.r, pc = j - d.c;
                if(inRange(pr, pc) && board[pr][pc] == me) continue;

                int cnt = 1;
                int nr = i + d.r, nc = j + d.c;
                while(inRange(nr, nc) && board[nr][nc] == me) {
                    cnt++;
                    nr += d.r;
                    nc += d.c;
                }
                
                if(cnt == 5) {
                    cout << me << endl;
                    cout << i << ' ' << j; 
                    return 0;
                }
            }
        }
    }

    cout << 0;
    return 0;
}