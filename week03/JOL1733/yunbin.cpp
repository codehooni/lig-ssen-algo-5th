#include <iostream>

using namespace std;

/*
문제 해결방안

1. N^2번의 바둑판 탐색을 진행한다.
2. 흰돌인지 검은돌인지 확인한 후 가로, 세로, 대각선 방향으로 탐색한다.
3. 같은 색의 돌이 연속으로 정확히 5개라면 탐색을 종료하고 결과를 출력한다.
   이때 6개 이상인 경우는 제외해야 한다.
4. 모든 방향을 탐색했는데도 5개가 없다면 0을 반환한다.

선택 근거

처음에는 모든 바둑알을 기준으로 가로, 세로, 대각선을 검사하려고 했습니다.
그런데 모든 바둑알을 동일한 조건으로 검사할 필요가 있을까? 라는 의문이 들었습니다.

생각해보니 순방향으로 탐색할 때 이전 위치에 같은 색의 돌이 존재한다면
굳이 현재 위치에서 다시 탐색할 필요가 없겠더군요.
방문을 넣을까 했지만 가로 방문 세로방문 대각선에대한 방문을 추가하는것은
코드 가독성이 너무 떨어질거같았습니다. 그래서 순방향이라는점에 다시 주목했고
이전 위치 즉 각 방향에따른 이전위치의 돌이 같은 돌이면 굳이 확인할필요가 없겠더군요
그래서 이전 위치를 확인하여 중복 탐색을 방지하도록 구현했습니다.

재귀함수를 생각했습니다. 반환 값으로 갯수를 리턴하는방식으로요
각 가로 세로 대각선은 dr,dc를 변형을해서 만들면 각 방향에 맞게 탐색 가능하겠더군요


AI 활용
    함수명 추천받았어요..
*/

int map[20][20];
int dr[4] = {0, 1, 1, -1};
int dc[4] = {1, 0, 1, 1};

void init()
{
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j < 20; j++)
        {
            cin >> map[i][j];
        }
    }
}

bool inRange(int r, int c)
{
    return r >= 1 && r <= 19 &&
           c >= 1 && c <= 19;
}

int dfs(int r, int c, int color, int d, int cnt)
{
    if (cnt > 5)
        return cnt;

    if (!inRange(r, c) || map[r][c] != color)
        return cnt;

    return dfs(r + dr[d], c + dc[d], color, d, cnt + 1);
}

int main(void)
{
    init();
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (map[i][j] == 0)
                continue;

            for (int d = 0; d < 4; d++)
            {

                int pr = i - dr[d];
                int pc = j - dc[d];

                if (inRange(pr, pc) && map[pr][pc] == map[i][j])
                    continue;

                if (dfs(i, j, map[i][j], d, 0) == 5)
                {
                    cout << map[i][j] << endl;
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}