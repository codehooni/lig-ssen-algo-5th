//0. 정점모양 : 트리
//1. 시작점 찾기 : wires배열의 각 행에 들어있는 노드들 중 1택.
//2. 인접점 : wires배열에 주어진 노드들끼리(간선으로 연결된 노드들), 인접리스트 제작,
//3. 끝점 : 모든 연결된 인접점방문(닿는데 까지)
//4. 방문표시 : 0 1
//5. BFS함수 : n회
//7.출력설계>>매번 하나씩 끊어가면서 BFS알고리즘 돌리기, 
//           해당 방식을할때 반복문 속에서 입력받은 벡터의 해당 노드
//           를 인접리스트에서 빼고 BFS를 돌려서 구한다.
/*
선택 근거: 맨 처음에 반복문에 BFS넣고 돌리면 안되지 않을까? 라는생각에 다른방식을 생각해봤는데
          (간선 최대 - 간선 두번째로많은노드 를 끊으면 되지않을까?)
          그 방식이 잘못되었단는걸 클로드에게 듣고, 고민해본결과 이방법밖에 생각이안나서 재환씨한테
          물어보니까 당신도 이방식으로 하셧다길래 이게 맞구나 하면서 선택했습니다...

핵심 로직: 인접 리스트를 만들고, BFS를 도는데, 이때 wires벡터에서 받아왓던 간선(노드 두개 입력받은벡터)를 반복문을 돌리면서
          하나씩 visited를 1로하여 스킵하는 방식, 이러면 간선이 끊어질때의 경우의수를 다 돌려볼 수있다.
          그렇게 BFS를 돌리고, 카운팅을 하여 연결되는 노드수를 재면, 나머지 노드수는 입력받은 n-카운팅이되고, 
          해당 두개의 차의 절대값을 리턴해주면 된다. 
시간 복잡도: 아마 O(n^2), for문 안에 while문 있어서
AI사용 : BFS로직의 개념은 이해를 했는데, 구현이 헷갈려서(c에선 front, rear로 구분했지만, c++엔 큐가 있어서) 조금 도움받았습니다.
        맨처음에 unsigned int min 으로 했었는데 전 unsigned int가 부호없는정수라 절댓값처럼 생각했는데 그게 아니더라구요
        계속 일부케이스에서 오류가 나서 이유를 찾아보니
        unsigned int 음수를 양수로 바꾸는게 아니라 음수의 부호비트를 그냥 정수의 비트로 읽어버려 아주 큰숫자가 나온다는 것을 배웠습니다.
*/



#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int min=1000;
    int cnt=1;
    vector<int>visited; //방문횟수
    vector<vector<int>>n_list(n+1); //인접리스트
    queue<int>q;
        for(auto& w : wires){
            n_list[w[0]].push_back(w[1]);
            n_list[w[1]].push_back(w[0]);
        } //인접리스트 만들기.
    for(int i=0; i<wires.size(); ++i){ //간선선택
    int node1 = wires[i][0]; //입력받은 배열의 간선
    int node2 = wires[i][1]; //노드
        int start=node1;
        visited.assign(n+1, 0);
        
        cnt=1;
        q.push(start);
        visited[start]=1;
        visited[node2]=1;
        while(!q.empty()){    //BFS시작
            int tmp = q.front();
            q.pop();
            for(auto nxt:n_list[tmp]){
                if(visited[nxt]!=1){
                q.push(nxt);
                visited[nxt]++;
                cnt++;
                }
            }
        }//BFS  끝
        int diff = cnt - (n-cnt);
        if(diff<0) diff = -diff;
        if(min>=diff){
            min = diff;
        }       
    }
    return min;

}