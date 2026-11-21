#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
1. 선택 근거: 보드의 각 점을 순회하면서 네가지 방향(가로, 세로, 우상향, 우하향)으로 오목여부 확인
2. 핵심 로직: 보드 위의 모든 점에서 [0을 만나거나] [보드의 끝에 도달]하기 전까지 계속 탐색한 뒤,
            한 번에 오목여부를 확인하여 6목 방지 + 이전돌 확인으로 중복탐색 방지
            board의 크기를 +2/+2로 잡아서 이전/이후 인덱스 비교 로직의 일관성 유지

AI사용: 5개 이상이 되는 각 줄의 시작점을 일일이 명시하지 않아도, 
보드의 크기와 오목의 조건이 19, 5로 작으므로 모든 점을 대입하는 것이 문제되지 않는다.
시간 복잡도: 보드 위 점 개수 (N^2) * 방향(4) * 보드 끝까지 탐색 O(N)이므로,
보드크기 MAX_L에 대해 O(N^3).
시간 복잡도를 줄이기 위해 각 방향의 시작점 리스트를 만들고자 하였으나,
MAX_L이 크지 않아서 오히려 코드만 꼬여 AI를 참조하여 Brute Force 탐색함
*/
#define MAX_L   19
#define OMOK    5
vector<vector<int>> board(MAX_L + 2, vector<int>(MAX_L + 2, 0));

int num, sx, sy;
vector<pair<int,int>> dir = {{0,1}, {1,0}, {-1, 1}, {1,1}};  // 각 줄의 탐색방향

// 경계도달 여부
bool isEnd (int x) { return (x < 1 | x > MAX_L);}

// (i,j)에서 시작하는 오목 탐색
bool isOmok(int i, int j) {
    int curC = board[i][j];
    if (curC == 0) return false;

    for (int d = 0; d < 4; d++) {
        // 이전 돌이 같은 색이면 중복탐색 방지
        if (board[i-dir[d].first][j-dir[d].second] == curC) continue;
        
        int cnt = 1;
        int curX = i + dir[d].first;
        int curY = j + dir[d].second;
        while(!isEnd(curX) && !isEnd(curY) && board[curX][curY] == curC) {
            cnt++;
            curX += dir[d].first;
            curY += dir[d].second;
        }
        if (cnt == OMOK) {
            cout << curC << endl << i << " " << j;
            return true;
        }
    }
    return false;
}

int main(void) {
    for (int i =1; i <= MAX_L; i++) for (int j=1; j <= MAX_L; j++) cin >> board[i][j];

    for (int i = 1; i <= MAX_L; i++) {
        for (int j = 1; j <= MAX_L; j++) {
            if (isOmok(i,j)) return 0;
        }
    }
    cout << "0" << endl;
    return 0;
}
