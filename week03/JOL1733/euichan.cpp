#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 코드를 너무 길게 적어서 정말 죄송합니다..

/*
1. 핵심 로직: 이전에 풀었던 빙고처럼 가로, 세로, 대각선을 나눠서 흑, 백이 5개가 연이어 되는 것이 있는지 검사한다.
             이 문제의 경우 6개 이상이면 안 된다는 예외 사항이 있기 때문에 해당 예외사항을 빼먹지 말고 검사하는 것이 핵심이다.

2. 선택 근거: 이전에 빙고 문제를 풀었던 경험으로 미루어보았을 때, 나눠서 푸는 것이 검증하기가 쉽다고 판단했다.
             또한, 계속해서 틀리는 부분을 분석해본 결과 예외사항을 잘 안 걸렀다는 것을 알게되어 예외사항고 코드에서 처리했다.
 */

/*
1. 검은 바둑알과 흰 바둑알을 교대로 놓아서 겨루는 게임이다.
2. 19줄 가로줄 19줄 세로줄 -> 19 * 19 배열 가능
3. 연속적으로 여섯 알 이상인 경우 인정되지 않는다. -> 특이조건
4. 가로, 세로, 대각선 모두 포함

결과 주어졌을 때, 판단하기
1) 가로 검사
2) 세로 검사
3) 대각선 검사 (상승)
4) 대각선 검사 (하강)

** 입력 조건
- 동시에 이기거나, 두 군데 이상 동시에 이기는 경우 없음
- 검 1 흰 2 빈 0
*/

int input_arr[21][21]; // 인덱스 1 ~ 19까지 사용하고, 6이상인지 검증하는 로직에서 다음 인덱스를 살피기 때문에 21까지 확장하여 추가
int arr[2] = { 0 };

void InputData(void)
{
    for (int i = 1; i <= 19; ++i)
    {
        for (int j = 1; j <= 19; ++j)
        {
            cin >> input_arr[i][j];
        }
    }
}

int CheckGaro(void)
{
    int b_cnt = 0; // 검은색이 연이어 몇 번 나왔는지 
    int w_cnt = 0; // 흰색이 연이어 몇 번 나왔는지

    bool b_prev = false; // 이전 값이 검은색이었는지
    bool w_prev = false; // 이전 값이 흰색이었는지

    for (int i = 1; i <= 19; ++i)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (input_arr[i][j] == 1)
            {
                if (b_prev)
                {
                    ++b_cnt;
                }
                else
                {
                    b_cnt = 1;
                    arr[0] = i;
                    arr[1] = j;
                }

                b_prev = true;
                w_prev = false;
            }
            else if (input_arr[i][j] == 2)
            {
                if (w_prev)
                {
                    ++w_cnt;
                }
                else
                {
                    w_cnt = 1;
                    arr[0] = i;
                    arr[1] = j;
                }

                b_prev = false;
                w_prev = true;
            }
            else
            {
                b_prev = false;
                w_prev = false;
            }

            if (b_cnt == 5)
            {
                if (input_arr[i][j+1] != 1) return 1;
            }
            if (w_cnt == 5)
            {
                if (input_arr[i][j+1] != 2) return 2;
            }
        }
        b_prev = false;
        w_prev = false;

        b_cnt = 0;
        w_cnt = 0;
    }

    return 0;
}

int CheckSero(void)
{
    int b_cnt = 0;
    int w_cnt = 0;

    bool b_prev = false;
    bool w_prev = false;

    for (int i = 1; i <= 19; ++i)
    {
        for (int j = 1; j <= 19; ++j)
        {
            if (input_arr[j][i] == 1)
            {
                if (b_prev)
                {
                    ++b_cnt;
                }
                else
                {
                    b_cnt = 1;
                    arr[0] = j;
                    arr[1] = i;
                }

                b_prev = true;
                w_prev = false;
            }
            else if (input_arr[j][i] == 2)
            {
                if (w_prev)
                {
                    ++w_cnt;
                }
                else
                {
                    w_cnt = 1;
                    arr[0] = j;
                    arr[1] = i;
                }

                b_prev = false;
                w_prev = true;
            }
            else
            {
                b_prev = false;
                w_prev = false;
            }

            if (b_cnt == 5)
            {
                if (input_arr[j + 1][i] != 1) return 1;
            }

            if (w_cnt == 5)
            {
                if (input_arr[j + 1][i] != 2) return 2;
            }
        }
        b_prev = false;
        w_prev = false;

        b_cnt = 0;
        w_cnt = 0;
    }

    return 0;
}

// 아래와 같이 하면 가로, 세로 합칠 수 있음

/*
// sero가 true면 행/열을 바꿔서 읽음
int Get(int i, int j, bool sero)
{
    return sero ? input_arr[j][i] : input_arr[i][j];
}

int CheckLine(bool sero)
{
    for (int i = 1; i <= 19; ++i)
    {
        int cnt = 0;   // 같은 색이 연속으로 몇 개인지
        int prev = 0;  // 직전 칸의 색 (0: 빈칸, 1: 검은색, 2: 흰색)

        for (int j = 1; j <= 19; ++j)
        {
            int cur = Get(i, j, sero);

            if (cur == 0)
            {
                cnt = 0;
            }
            else if (cur == prev)
            {
                ++cnt;
            }
            else // 새로운 연속 구간 시작
            {
                cnt = 1;
                arr[0] = sero ? j : i;
                arr[1] = sero ? i : j;
            }
            prev = cur;

            // 정확히 5개이고, 다음 칸이 같은 색이 아니면 승리
            if (cnt == 5 && Get(i, j + 1, sero) != cur)
                return cur;
        }
    }
    return 0;
}

*/

int CheckRise(void)
{
    int b_cnt = 0;
    int w_cnt = 0;

    bool b_prev = false;
    bool w_prev = false;

    // 여기는 윗대각선 검증
    // 5행 1열부터 시작 (4행 1열까지는 대각선 요소가 4개이므로)
    for (int i = 5; i <= 19; i++)
    {
        int sum = i + 1;

        for (int j = 1; j != i; j++)
        {
            int x = sum - j;
            
            if (input_arr[x][j] == 1)
            {
                if (b_prev)
                {
                    ++b_cnt;
                }
                else
                {
                    b_cnt = 1;
                    arr[0] = x;
                    arr[1] = j;
                }

                b_prev = true;
                w_prev = false;
            }
            else if (input_arr[x][j] == 2)
            {
                if (w_prev)
                {
                    ++w_cnt;
                }
                else
                {
                    w_cnt = 1;
                    arr[0] = x;
                    arr[1] = j;
                }

                b_prev = false;
                w_prev = true;
            }
            else
            {
                b_prev = false;
                w_prev = false;
            }
        
            if (b_cnt == 5)
            {
                if (input_arr[x + 1][j + 1] != 1) return 1;
            }
            if (w_cnt == 5)
            {
                if (input_arr[x + 1][j + 1] != 2) return 2;
            }
        }

        b_prev = false;
        w_prev = false;

        b_cnt = 0;
        w_cnt = 0;
    }

    // 여기는 아래 대각선 검증
    // 2행 19열부터
    for (int i = 2; i <= 15; i++)
    {
        int sum = i + 19;
        
        for (int j = 19; j != i; j--)
        {
            int x = sum - j;
            
            if (input_arr[x][j] == 1)
            {
                if (b_prev)
                {
                    ++b_cnt;
                    arr[0] = x;
                    arr[1] = j;
                }
                else
                {
                    b_cnt = 1;
                    // arr[0] = x;
                    // arr[1] = j;
                }

                b_prev = true;
                w_prev = false;
            }
            else if (input_arr[x][j] == 2)
            {
                if (w_prev)
                {
                    ++w_cnt;
                    arr[0] = x;
                    arr[1] = j;
                }
                else
                {
                    w_cnt = 1;
                    // arr[0] = x;
                    // arr[1] = j;
                }

                b_prev = false;
                w_prev = true;
            }
            else
            {
                b_prev = false;
                w_prev = false;
            }
            if (b_cnt == 5)
            {
                if (input_arr[x - 1][j - 1] != 1) return 1;
            }
            if (w_cnt == 5)
            {
                if (input_arr[x - 1][j - 1] != 2) return 2;
            }
        }
        
        b_prev = false;
        w_prev = false;

        b_cnt = 0;
        w_cnt = 0;
    }

    return 0;
}

int CheckFall(void)
{
    int b_cnt = 0;
    int w_cnt = 0;

    bool b_prev = false;
    bool w_prev = false;

    for (int i = 1; i <= 15; i++)
    {
        int diff = i - 1;

        for (int j = 1; j <= 20 - i; j++)
        {
            int y = diff + j;
            
            if (input_arr[j][y] == 1)
            {
                if (b_prev)
                {
                    ++b_cnt;
                }
                else
                {
                    b_cnt = 1;
                    arr[0] = j;
                    arr[1] = y;
                }

                b_prev = true;
                w_prev = false;
            }
            else if (input_arr[j][y] == 2)
            {
                if (w_prev)
                {
                    ++w_cnt;
                }
                else
                {
                    w_cnt = 1;
                    arr[0] = j;
                    arr[1] = y;
                }

                b_prev = false;
                w_prev = true;
            }
            else
            {
                b_prev = false;
                w_prev = false;
            }

            if (b_cnt == 5)
            {
                if (input_arr[j + 1][y + 1] != 1) return 1;
            }

            if (w_cnt == 5)
            {
                if (input_arr[j + 1][y + 1] != 2) return 2;
            }
        }

        b_cnt = 0;
        w_cnt = 0;
        
        b_prev = false;
        w_prev = false;
    }

     for (int i = 5; i <= 18; i++)
    {
        int diff = i - 19;
        
        for (int j = 19; j >= 1; j--)
        {
            int y = diff + j;
            
            if (input_arr[j][y] == 1)
            {
                if (b_prev)
                {
                    ++b_cnt;
                    arr[0] = j;
                    arr[1] = y;
                }
                else
                {
                    b_cnt = 1;
                    // arr[0] = j;
                    // arr[1] = y;
                }

                b_prev = true;
                w_prev = false;
            }
            else if (input_arr[i][y] == 2)
            {
                if (w_prev)
                {
                    ++w_cnt;
                    arr[0] = j;
                    arr[1] = y;
                }
                else
                {
                    w_cnt = 1;
                    // arr[0] = j;
                    // arr[1] = y;
                }

                b_prev = false;
                w_prev = true;
            }
            else
            {
                b_prev = false;
                w_prev = false;
            }

            if (b_cnt == 5)
            {
                if (input_arr[j - 1][y - 1] != 1) return 1;
            }

            if (w_cnt == 5)
            {
                if (input_arr[j - 1][y - 1] != 2) return 2;
            }
        }
    }

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    InputData();

    int ans = 0;

    if (ans = CheckGaro())
    {
        cout << ans << '\n';
        cout << arr[0] << " " << arr[1] << '\n';
        return 0;
    }

    if (ans = CheckSero())
    {
        cout << ans << '\n';
        cout << arr[0] << " " << arr[1] << '\n';
        return 0;
    }

    if (ans = CheckRise())
    {
        cout << ans << '\n';
        cout << arr[0] << " " << arr[1] << '\n';
        return 0;
    }

    if (ans = CheckFall())
    {
        cout << ans << '\n';
        cout << arr[0] << " " << arr[1] << '\n';
        return 0;
    }
    else
    {
        cout << ans << '\n';
        return 0;
    }

    return 0;
}