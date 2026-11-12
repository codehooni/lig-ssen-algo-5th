#include <string>
#include <vector>

using namespace std;

// 선택 근거: 전력망이 트리 구조이므로 전선 하나를 제거하면 반드시 두 개의 연결 요소로 분리됨.
//           각 전선을 제거한 뒤 BFS로 한쪽 연결 요소의 송전탑 개수를 계산하는 방식 채택.
// 핵심 로직: 인접 행렬로 그래프 구성 → 전선 하나 제거 → BFS로 연결된 송전탑 개수 계산
//           → 두 전력망의 송전탑 개수 차이 비교 → 전선 복구 후 다음 전선 탐색.
// 시간 복잡도: O(N^3), N은 송전탑 개수.


int minimum_difference=100;
int difference=100;
int graph[101][101]={0};
int Queue[101];
int count;

// n,wires 입력받아 n*n 배열망 graph 작성.
void wires_to_graph(int n,vector<vector<int>> wires){
    for(int i=0;i<n-1;i++){
        int a=wires[i][0];
        int b=wires[i][1];
        
        graph[a][b]=1;
        graph[b][a]=1;
    }
}

// 전선 한 개 절단한 그래프와 시작점을 입력받으면 송전탑 개수 차이를 반환.
void search_one_graph(int n,int a){
    int visited[101]={0};
    int front=0;
    int rear=0;
    count=0;
    
    Queue[rear++]=a;
    visited[a]=1;
    
    while(front!=rear){
        int curr=Queue[front++];
        count++;
        
        for(int i=1;i<n+1;i++){
            if( (visited[i]==0) && (graph[curr][i]==1) ){
                Queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}

// wires에 있는 모든 전선에 대하여, 해당 전선을 절단한 graph에 search_one_graph() 이행하여 송전탑 개수 차이 최소값 탐색.
void search_all_graph(int n, vector<vector<int>> wires){
    for(int i=0;i<n-1;i++){
        int a=wires[i][0];
        int b=wires[i][1];
        
        graph[a][b]=0;
        graph[b][a]=0;
        
        search_one_graph(n,a);
        
        difference=abs(n-2*count);
        
        if(difference<minimum_difference){
            minimum_difference=difference;
        }
        
        graph[a][b]=1;
        graph[b][a]=1;
    }
}

int solution(int n, vector<vector<int>> wires) {
    minimum_difference=n;
    difference=n;
    
    wires_to_graph(n,wires);
    search_all_graph(n, wires);
    
    return minimum_difference;
}