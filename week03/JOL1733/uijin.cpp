#include <stdio.h>
#include <iostream>
using namespace std;

// 선택 근거: 19×19 오목판의 모든 돌을 순회하면서 4방향을 검사하는 완전탐색 방식
// 핵심 로직: 
// 1.값이 0이 아닌 arr[i][j]를 시작점으로 설정.
// 2. 가로, 세로, 우측 아래, 우측 위 방향으로 연속된 5개의 돌이 같은 색인지 검사.
// 3. 시작점과 끝점 바깥의 돌까지 검사하여 6목 이상인 경우 제외.
// 4. 오목이 성립하면 돌의 색과 시작 좌표(i, j)를 출력하고 탐색 종료. 승자가 없으면 0 출력.
// 구현 특징: 배열 외곽을 0으로 초기화하여 경계 검사를 단순화하고, short-circuit 평가로 불필요한 비교 방지.
// 시간 복잡도: O(N^2)

#define MAX_N 19
int arr[MAX_N+2][MAX_N+2]={0};

// 오목 성립 탐지용 변수
bool search_finish=false;
int winner_stone=0;
int winner_i=0;
int winner_j=0;
int direct_vector[4][2]={{1,0},{0,1},{1,1},{-1,1}}; // 문제에서 요구한 대로 오목 발견 시작점을 반환하도록 방향값 설정. 

// 입력값을 오목판에 저장.
void Input(){
    for(int i=1;i<20;i++){
        for(int j=1;j<20;j++){
            cin >> arr[i][j];
        }
    }
}

// 4방향 판별함수. 시작점부터 방향값의 배수를 이용해 연속된 돌을 체크. 오목 성립하면 즉시 판별 종료.
// 오목 성립 기준 : (arr[i][j]가 0이 아님) && ((i+4*di,j+4*dj)가 모두 1이상 19이하) && (다섯 개까지는 서로 같고) && (여섯째는 다름) && (시작점 반대 방향도 다름) ).
void check_four_direction(int i,int j){
    for(int n=0;n<4;n++){
        int di=direct_vector[n][0];
        int dj=direct_vector[n][1];
        if( (arr[i][j]!=0) && (0<i+4*di) && (i+4*di<20) && (0<j+4*dj) && (j+4*dj<20) && (arr[i][j]==arr[i+di][j+dj]) && (arr[i+di][j+dj]==arr[i+2*di][j+2*dj]) && (arr[i+2*di][j+2*dj]==arr[i+3*di][j+3*dj]) && (arr[i+3*di][j+3*dj]==arr[i+4*di][j+4*dj]) && (arr[i+4*di][j+4*dj]!=arr[i+5*di][j+5*dj]) && (arr[i-di][j-dj]!=arr[i][j]) ){
            search_finish=true;
            return;
        }
    }
}

// 빈칸이 아닌 모든 좌표에서 판별함수 호출. 오목이 성립하면 해당 돌의 색과 시작 좌표를 기록하고 즉시 탐색 종료.
void OhMork_Check(){
    for(int i=1;i<20;i++){
        for(int j=1;j<20;j++){
            if(arr[i][j]!=0){
                check_four_direction(i,j);
                if (search_finish){
                    winner_stone=arr[i][j];
                    winner_i=i;
                    winner_j=j;
                    return;
                }
            }
        }
    }
}

int main(){
    Input();
    OhMork_Check();

    cout << winner_stone << "\n";
    if(winner_stone!=0){
        cout << winner_i << " " << winner_j;
    }

    return 0;
}