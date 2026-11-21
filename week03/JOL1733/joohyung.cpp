#include <iostream>
#define MAX_N (19)
using namespace std;

/*
 * 풀이 방법: 완전 탐색
 *
 * 선택 근거:
 * 
 *
 *
 * 핵심 로직:
 * 1. 오목판을 이차원 배열로 받아오고 각 좌표당 방향 별로의 연속값을 저장하는 별도의 이차원 배열 구현
 * 2. 왼쪽에서 부터 방향 별 연속 값을 누적한다
 * 
 *
 * 시간복잡도: O(N^2)
 */

typedef struct _record{
    int sum[4]; // 세로, 가로, 좌상단, 우상단 대각선 방향 별로 몇개가 누적되어 있는지

}record;

int arr[MAX_N+2][MAX_N+2]={0};
record acc[MAX_N+2][MAX_N+2]={0}; // 각 칸에 "이 돌에서 끝나는 같은 색 연속 길이"를 방향별로 저장해 둡니다.
int dr[4] = {-1,0,-1,1}; //밑, 오른쪽, 좌상단 대각선, 우상단 대각선 방향으로 이동하기 위한 행의 변화량 
int dc[4] = {0,-1,-1,-1};  //밑, 오른쪽, 좌상단 대각선, 우상단 대각선 방향으로 이동하기 위한 열의 변화량

void input_data() {
    for (int i=1;i<=MAX_N;i++){
        for (int j=1;j<=MAX_N;j++)
           {
            cin >> arr[i][j];
            if (arr[i][j])
                 for (int k=0;k<4;k++)
                    {
                        acc[i][j].sum[k]=1; // 자기 자신이 연속의 출발점이다
                    }
           }
    }
}

int main(){
    input_data();
    for (int j=1;j<=MAX_N;j++){ // 이전 칸이 모두 왼쪽 열 또는 같은 열 위쪽이므로, 열 우선으로 돌아야 누적값이 먼저 채워진다
        for(int i=1;i<=MAX_N;i++){
            for (int k=0;k<4;k++){
                if (arr[i][j] !=0 && arr[i][j]==arr[i+dr[k]][j+dc[k]]){
                    acc[i][j].sum[k]+=acc[i+dr[k]][j+dc[k]].sum[k];
                    if (acc[i][j].sum[k]==5 && arr[i][j]!=arr[i-dr[k]][j-dc[k]])
                    {
                        cout<<arr[i][j]<<endl;
                        cout << i+dr[k]*4<<" "<<j+dc[k]*4;
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0;
    return 0;
     
}