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

void bfs(vector<vector<int>> wires,int n){
    for(auto& num : wires){
        queue<int> left_que;
        queue<int> right_que;
        
        int left=1,right=1;
        left_que.push(num[0]);
        right_que.push(num[1]);
        vector<int> visited(n+1,0);
        visited[num[0]] =1;
        visited[num[1]] =1;
        while(!left_que.empty() || !right_que.empty()){
            
            if(!left_que.empty()){
                int left_index = left_que.front();left_que.pop();
                vector<int> left_grp = grap[left_index];
                for(int i : left_grp){
                //간선을 끊어야한다.
                if((left_index==num[0] && i==num[1]) ||
                   (i==num[0] && left_index == num[1]|| visited[i])) continue;
                
                visited[i]=1;
                left++;
                left_que.push(i);
                }
            }
            if(!right_que.empty()){
                int right_index = right_que.front(); right_que.pop();
                vector<int> right_grp = grap[right_index];
                for(int i : right_grp){
                if(right_index == num[0] &&i==num[1] ||
                   i == num[1] && right_index == num[1] || visited[i]) continue;
                
                visited[i]++;
                right++;
                right_que.push(i);
                }
            }
        }
        answer = min(answer,abs(left-right));
        
    }
}
int solution(int n, vector<vector<int>> wires) {
    init(wires);
    bfs(wires,n);
    return answer;
}