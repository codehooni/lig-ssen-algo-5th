#include <string>
#include <vector>
#include <queue>
using namespace std;

// 접근 방식 : BFS
// 풀이 로직
// 1.field의 크기 n, m을 구하고 arr의 [1~n][1~m] 영역에 각 문자를 저장한다. 출발점 S와 도착점 E의 좌표를 구한다.
//  arr의 외곽을 '#'으로 채워 격자 외부로의 이동을 방지한다.(solution 복수 실행을 고려하여 초기화 실시.)
// 2. 구조체를 생성해 좌표, 누적 거리, 진입 횟수를 관리한다.
// 3. 출발 상태를 큐에 삽입하고 방문 기록을 갱신한다. 
// 4. 큐에서 front를 꺼내고 네 방향을 탐색한다.
//    -건물이 있거나 레이더 진입 횟수가 k 초과인 방향일 경우 탐색 제외
//    -좌표와 레이더 진입 횟수 조합이 미방문 상태이면 방문 기록 갱신하고 큐에 삽입.
// 5.  도착점에 도달하면 누적 이동 거리 반환.
// 6. 큐를 전부 비운 뒤에도 도착하지 못하면 -1 반환.
//
// 시간 복잡도 : O(n*m*(k+1))

char arr[100+2][100+2]={};
bool visited[102][102][11]={};  // 좌표, 레이더 진입 횟수 별 방문 기록

//좌표 관리 구조체
struct coordinate{
    int row;
    int col;
};
coordinate Start;
coordinate End;

// 탐색 상태 관리 구조체
struct info{
    int row_index;
    int col_index;
    int total_distance;
    int radar_count;
};

const int dr[4]={-1,1,0,0};
const int dc[4]={0,0,-1,1};

// field 문자 입력. 출발점과 도착점 좌표 기록. 
void Input(const vector<string>& field){
    memset(arr,'#',sizeof(arr));
    int n=field.size();
    int m=field[0].size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            arr[i+1][j+1]=field[i][j];
            if (field[i][j]=='S'){
                Start.row=i+1;
                Start.col=j+1;
            }
            else if (field[i][j]=='E'){
                End.row=i+1;
                End.col=j+1;
            }
        }
    }
}

int BFS(int k){
    queue<info> q;
    memset(visited,0,sizeof(visited));

    // 큐에 출발 상태 등록
    q.push( {Start.row,Start.col,0,0} );
    visited[Start.row][Start.col][0]=true;

    while (!q.empty()){
        info current=q.front();
        q.pop();

        if (current.row_index==End.row && current.col_index==End.col) {
            return current.total_distance;  // 도착점에 도달 시 이동거리 반환
        }

        // 네 방향 탐색
        for (int i=0;i<4;i++) {
            info new_info={ current.row_index+dr[i], current.col_index+dc[i], current.total_distance+1, current.radar_count };

            if ( arr[new_info.row_index][new_info.col_index]=='#'){ continue;}
            if (arr[new_info.row_index][new_info.col_index]=='R') {
                    new_info.radar_count+=1;
                    if(new_info.radar_count > k) {
                        continue;
                    }
            }
            if (!visited[new_info.row_index][new_info.col_index][new_info.radar_count]) {
                    visited[new_info.row_index][new_info.col_index][new_info.radar_count]=true;
                    q.push(new_info);
            }
        }
    }
    return -1;
}

int solution(vector<string> field, int k) {
    Input(field);
    return BFS(k);
}