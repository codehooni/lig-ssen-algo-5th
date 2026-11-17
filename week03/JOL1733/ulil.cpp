#include <bits/stdc++.h>
using namespace std;

//1. 핵심 로직: 모든 칸을 돌면서, 돌이 있는 칸에서 4방향(→, ↓, ↘, ↗)으로 같은 색이 몇 개 이어지는지 센다.
//              반대쪽 한 칸(출발점 이전의 칸)이 같은 색이면 줄의 시작이 아니므로 건너뛴다.
//              줄의 시작에서 끝까지 세서 딱 5개일 때만 승리로 보고, 6개 이상은 승리가 아니다.
//              이기면 돌 색과 출발 칸(r, c)을 출력하고 바로 끝내며, 끝까지 못 찾으면 0을 출력한다.
//2. 선택 근거:  4 방향이 모두 오른쪽이나 아래로 가서, 출발한 돌이 그 줄의 가장 왼쪽(세로면 가장 위) 돌이 된다.
//              배열을 21 x 21로 잡고 1~19만 써서, 테두리가 0이라 판 밖으로 나가면 while문이 자동으로 멈춘다.
//              방향별 이동량을 dr, dc 배열에 넣어 두면 r += dr[d], c += dc[d] 두 줄로 4방향을 다 처리할 수 있다.

#define MAX_N 21
int arr[MAX_N][MAX_N];

int dr[] = { 0, 1, 1, -1 }; // →, ↓, ↘, ↗
int dc[] = { 1, 0, 1,  1 };

void input_data(void){
    for(int i = 1; i <= 19; i++){
        for (int j = 1; j <= 19; j++){
            cin >> arr[i][j];
        }
    }
}
int count(int r, int c, int d){
    int start = arr[r][c];
    int cnt = 0;
    while( arr[r][c] == start ){
        cnt++;
        r += dr[d]; //방향별 이동 방법을 생각해내지 못함(AI 활용)
        c += dc[d];
    }
    return cnt;
}
int main(void){
    input_data();
        //이 문제에선 r과 c를 바꿔도 상관없는데 가장 왼쪽에 있는 바둑알을 판단하기 위해 열을 먼저 실행
    	for (int c = 1; c <= 19; c++) {         
		    for (int r = 1; r <= 19; r++) {
			    if (arr[r][c] == 0) continue;    
            
            for (int d = 0; d < 4; d++){
                int pr = r - dr[d]; 
                int pc = c - dc[d];
                if(arr[pr][pc] == arr[r][c])continue;

                if(count(r,c,d) == 5){
                    cout << arr[r][c] << endl;
                    cout << r << " " << c << endl;
                    return 0;
                }
            }
        }
        }

        cout << 0 << endl;
        return 0;
}
