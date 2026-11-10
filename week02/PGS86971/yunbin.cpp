#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
// 입력 wires를 이용해보자
// bfs 방식으로 진행한다 모두 연결되어있다고 보장되어있으니 
// 각각의 왼쪽 큐 오른쪽 큐를 만든다. 
// 왼쪽큐,오른쪽큐의 시작은 입력받은 wires 0번인덱스 1번인덱스를 사용하고자한다.
// 모두 순회를 하여 왼쪽과 오른쪽이 총 몇개의 노드를 방문했는지의 차를 구한후 절대값으로한다.
// 해당 절대값이 가장 낮은 놈을 고르면 되는 문제가 아니겠는가
// min(),abs()를 사용해보자

using namespace std;
int answer = 101; //해당 노드의 차의 절대값이 n을 넘지않을테니
unordered_map<int,vector<int>> grap; // 노드의 정보를 담은 그래프

void init(vector<vector<int>> wires){
    for(auto& num : wires){
        grap[num[0]].push_back(num[1]);
        //무방향이랑 양쪽에대입
        grap[num[1]].push_back(num[0]);
    }
}

//개선한 bfs
void bfs(vector<vector<int>> wires,int n){
    for(auto& num : wires){
        queue<int> que;
        int node_length=1;
        que.push(num[0]);
        vector<int> visited(n+1,0);
        visited[num[0]] =1;
        
        while(!que.empty()){
            int index =que.front();que.pop();
            vector<int> grp = grap[index];
            for(int i : grp){
                if((index==num[0] && i==num[1]) ||
                    (i==num[0] && index == num[1]|| visited[i])) continue;
                
                 visited[i]=1;
                 node_length++;
                 que.push(i);
            }
        }
        answer = min(answer, abs(node_length - (n - node_length)));
    }
}

//초기 bfs
// void bfs(vector<vector<int>> wires,int n){
//     //wires는 각 요소는 노드간의 연결을 말해준다.
//     //그렇다면 배열의 요소를 통해 노드의 연결을 끊어버리면 어떨까?에서 시작했다.
//     for(auto& num : wires){
//         //각각 왼쪽과 오른쪽 노선의 정보를 담을 큐이다.
//         queue<int> left_que;
//         queue<int> right_que;
//         //자신을 포함해야하므로 1로 초기화한다.
//         int left=1,right=1;
//         //초기 노드 삽입
//         left_que.push(num[0]);
//         right_que.push(num[1]);
//         //bfs방식이기에 방문 표시를 할필요가있다.
//         vector<int> visited(n+1,0);
//         visited[num[0]] =1;
//         visited[num[1]] =1;
//         //각 큐 끝까지 탐색한다
//         while(!left_que.empty() || !right_que.empty()){
            
//             if(!left_que.empty()){
//                 int left_index = left_que.front();left_que.pop();
//                 //꺼내온 인덱스와 인접한 모든노드의 정보를담은 백터 추출 
//                 vector<int> left_grp = grap[left_index];
//                 for(int i : left_grp){
//                 //간선을 끊어야한다. 이 부분이 힘들었다.
//                 if((left_index==num[0] && i==num[1]) ||
//                    (i==num[0] && left_index == num[1]|| visited[i])) continue;
                
//                 visited[i]=1;
//                 left++;
//                 left_que.push(i);
//                 }
//             }
//             if(!right_que.empty()){
//                 int right_index = right_que.front(); right_que.pop();
//                 vector<int> right_grp = grap[right_index];
//                 for(int i : right_grp){
//                 if(right_index == num[0] &&i==num[1] ||
//                    i == num[1] && right_index == num[1] || visited[i]) continue;
                
//                 visited[i]++;
//                 right++;
//                 right_que.push(i);
//                 }
//             }
//         }
//         answer = min(answer,abs(left-right));
        
//     }
// }
int solution(int n, vector<vector<int>> wires) {
    init(wires);
    bfs(wires,n);
    return answer;
}