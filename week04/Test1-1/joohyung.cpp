#include <string>
#include <vector>
#include <queue>
#include <cstring>

// 핵심 아이디어: BFS 
// 시간 복잡도: O(N^2) 
// 아이디어 로직: 정점의 모양을 2차원 노드가 아닌 현재 얼마나 jamming을 사용했는지를 포함하는 3차원 노드를 활용하여 값을 설정한다 

using namespace std;
typedef struct State{
    int r,c,used; // r: 행 좌표, c: 열 좌표, used: jamming을 얼마나 활용하였는지
} State;
int dr[4]={-1,1,0,0}; // 상, 하, 좌, 우
int dc[4]={0,0,-1,1}; // 상, 하, 좌, 우
int dist[101][101][11]={0}; // 현재 state까지 도달하는데 얼마나 걸렸는지 jamming used까지 포함하기 위해서 3차원으로 배열을 확장

int BFS(vector<string>&field, int k, State & start, State & end){
    queue<State> q;
    q.push(start);
    while(!q.empty()){
        State cur = q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr<0 || nr>=field.size() || nc<0 || nc>=field[0].length() || field[nr][nc]=='#' ) // 탐색이 가능한지 확인
                continue;
            int nused = cur.used + (field[nr][nc]=='R' ? 1:0);
            if (nused > k) continue; // Jamming 사용 횟수가 초과한 경우
            State next={nr,nc,nused};
            if (dist[nr][nc][nused]==-1){
                dist[nr][nc][nused]=dist[cur.r][cur.c][cur.used]+1;
                if (nr==end.r && nc==end.c) return dist[nr][nc][nused];
                q.push(next);
            }
            
        }
    }
    return -1;
}
int solution(vector<string> field, int k) {
    // 여기에 코드를 작성하세요.
    State start, end; // 시작할 
    memset(dist, -1, sizeof(dist)); // 거리 -1로 초기화


    // Step1: 시작 지점과 종료 지점 저장
    for (int i=0;i<field.size();i++){
        for(int j=0;j<field[0].length();j++)
        {
            if (field[i][j]=='S'){
                start.r=i;
                start.c=j;
                start.used = 0;
                dist[i][j][0]=0; // 시작 노드 값 설정
            }
            else if (field[i][j]=='E'){
                end.r=i;
                end.c=j;
                end.used = 0;
            }
        }
    }

    // Step 2: BFS를 통하여 문제 해결
    int result = BFS(field,k,start,end);
    return result;
}
