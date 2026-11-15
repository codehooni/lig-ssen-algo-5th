#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

#define MAX_N (100+2)

using namespace std;

/**
 * 1. 핵심 로직: BFS를 활용 
 * 2. 선택 근거: 두 정점을 끊었을때 각각의 네트워크의 길이를 구하기에 BFS 방식이 가장 적절하다고 생각
 */

bool arr[MAX_N][MAX_N]={0}; // 연결 여부를 인접행렬로 나타내기 위한 2차원 배열

int BFS(int start,int n) {
    bool visited[MAX_N]={0};
    queue<int> q;
    visited[start]=1;
    int cnt =1;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=1;i<=n;i++) {
            if(arr[cur][i] && !visited[i]){
                cnt++;
                visited[i]=true;
                q.push(i);
            }
        }
    }
    
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    // Step 1: 인접행렬 설정
    for(int i=0;i<wires.size();i++)
    {
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
    }


    // Step 2: 특정 
    for (int i=0;i<wires.size();i++) {
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        arr[v1][v2] = 0;
        arr[v2][v1] = 0;
        // BFS함수 호출
        int delta=abs(BFS(v1,n)-BFS(v2,n));
        if (delta<answer){
            answer=delta;
        }
        
        arr[v1][v2]=1;
        arr[v2][v1]=1;
    }
    
    return answer;
}