#include <iostream>
using namespace std;

int omuck[19][19] = { 0 };

int nx[4] = { 1, 1, 0, -1 };
int ny[4] = { 1, 0, 1, 1 };
// 오른쪽 아래, 아래, 오른쪽, 오른쪽 위

int main() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> omuck[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (omuck[i][j] == 1 || omuck[i][j] == 2) {
                int current = omuck[i][j];

                for (int k = 0; k < 4; k++) {
                    // 이 방향으로 이어진 줄의 첫 돌인지 확인
                    int prev_x = i - nx[k];
                    int prev_y = j - ny[k];

                    if (prev_x >= 0 && prev_x < 19 &&
                        prev_y >= 0 && prev_y < 19 &&
                        omuck[prev_x][prev_y] == current) {
                        continue;
                    }

                    int dnx = i + nx[k];
                    int dny = j + ny[k];

                    if (dnx >= 0 && dnx < 19 &&
                        dny >= 0 && dny < 19 &&
                        omuck[dnx][dny] == current) {
                        int count = 2;
                        dnx += nx[k];
                        dny += ny[k];

                        while (dnx >= 0 && dnx < 19 &&
                            dny >= 0 && dny < 19 &&
                            omuck[dnx][dny] == current) {
                            dnx += nx[k];
                            dny += ny[k];
                            count++;
                        }

                        if (count == 5) {
                            cout << current << '\n';
                            cout << i + 1 << ' ' << j + 1;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << 0;
    return 0;
}