#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
    시간 복잡도: O(N^2) (문자열 초기화 등 있긴 한데 크지 않을 것 같음)
    접근 방식: 행, 열, 대각선별로 string 배열을 만들고 스택처럼 바둑알을 쌓으며 비교함.
    선택 근거: 지점별로 동일한 바둑알이 5개 놓였는지 검사하기 위해 string을 스택처럼 활용.
    핵심 로직:
        1. 전체 바둑판을 순회하며 각 행, 열, 대각선에 다음 조건을 고려하며 바둑알을 쌓음
            a. 이전 위치와 동일한 바둑알이면 1개 추가함
            b. 현재 바둑알이 다르고 쌓인 바둑알이 5개가 아니면 새로운 바둑알로 변경
        2. 행, 열, 대각선 각각 1에서 고려하지 못한 1, 19 끝점 부분 재검사
        3. 승자가 결정나면 승자와 가장 왼쪽 좌표 출력하고 아니면 0 출력
*/

#define N 19
char board[N + 1][N + 1];
string dr[2 * N + 1];
string dl[2 * N + 1];
string rw[N + 1];
string cl[N + 1];
char win = '0';
int x, y;

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

bool check(string *s, int idx, char v) {
    auto & loc = s[idx];

    if (loc.empty() || loc.back() == v) {
        loc += v;
        return false;
    }

    if (loc.size() != 5 || loc.back() == '0') {
        loc = v;
        return false;
    }

    return true;
}

bool checkWin(int i, int j) {
    char v = board[i][j];

    if (check(rw, i, v)) {
        win = rw[i].back();
        y = i;
        x = j - 5;
        return true;
    }

    if (check(cl, j, v)) {
        win = cl[j].back();
        y = i - 5;
        x = j;
        return true;
    }

    if (check(dr, i + j, v)) {
        win = dr[i + j].back();
        y = i - 1;
        x = j + 1;
        return true;
    }

    if (check(dl, N + i - j, v)) {
        win = dl[N + i - j].back();
        y = i - 5;
        x = j - 5;
        return true;
    }

    return false;
}

// 극값 고려
bool checkPole() {
    // r -> c == N
    for (int i = 1; i <= N; i++) {
        if (rw[i].size() != 5 || rw[i].back() == '0') continue;
        win = rw[i].back();
        y = i;
        x = N - 4;
        return true;
    }

    // c -> r == N
    for (int i = 1; i <= N; i++) {
        if (cl[i].size() != 5 || cl[i].back() == '0') continue;
        win = cl[i].back();
        y = N - 4;
        x = i;
        return true;
    }

    // dr -> r == N
    for (int i = 1; i <= N - 4; i++) 
    {
        if (dr[N + i].size() != 5 || dr[N + i].back() == '0') continue;
        win = dr[N + i].back();
        y = N;
        x = i;
        return true;
    }

    // dr -> c == 1
    for (int i = 5; i <= N; i++) {
        if (dr[1 + i].size() != 5 || dr[1 + i].back() == '0') continue;
        win = dr[1 + i].back();
        y = i;
        x = 1;
        return true;
    }

    // dl -> r == N
    for (int i = 5; i <= N; i++) {
        if (dl[N + N - i].size() != 5 || dl[N + N - i].back() == '0') continue;
        win = dl[N + N - i].back();
        y = N - 4;
        x = i - 4;
        return true;
    }

    // dl -> c == N
    for (int i = 1; i <= N - 4; i++) {
        if (dl[N + i - N].size() != 5 || dl[N + i - N].back() == '0') continue;
        win = dl[N + i - N].back();
        y = i;
        x = N - 4;
        return true;
    }
    
    return false;
}

void solution() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (checkWin(i, j)) {
                cout << win << endl;
                cout << y << " " << x << endl;
                return;
            }
        }
    }

    if (checkPole()) {
        cout << win << endl;
        cout << y << " " << x << endl;
        return;
    }

    cout << "0" << endl;
}

int main(void) {
    input_board();
    solution();
    return 0;
}