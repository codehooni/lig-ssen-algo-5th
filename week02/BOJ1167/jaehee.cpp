#include<iostream>
#include<vector>
#include<stack>
using namespace std;
stack<int>tree;
/*
문제풀이/실패/
선택근거 : 맨 처음 DFS로 시작지점에서 가장 먼 노드까지 거리가 가장 길거니까
          지름이겠네? 쉽네? 하면서 로직을 클로드한테 설명해주니 
          그건 반쪽짜리 로직이야! 하면서 혼났습니다.
          이후 클로드한테 설명들으면서 짜보다가 시간이 늦어 제출합니다...
핵심로직 : DFS왕복(시작노드->가장 먼 노드 & 이후 가장먼 노드->거기서부터
          가장 먼노드사이의 거리)
시간복잡도
AI사용:제가 맨처음 생각했던 로직(맨 처음 DFS로 시작지점에서 가장 먼 노드까지 거리가 가장 길거니까
          지름이겠네?)가 반만 맞고, 가장 멀었던 노드에서 한번 더 DFS를 돌려
          거기서 가장 먼 노드를 찾는 로직이 지름을 구하는 로직이라는 점을
          깨닫고 나니 길은 보이는데, 구현은 아직 어려움이 많아 도움을 받고
          있었습니다.
          결론: 트리의 지름은 단순한 부모(시작)노드에서의 가중치의합(거리)가
          아니라 가장 먼 노드-거기서 가장 먼 노드 사이의 거리가 트리의 지름이다.
          또한 DFS를 수업때했던것 처럼 재귀로 풀어보고싶었는데
          구현을 못하겠어서 저번에 사용했던 stack으로 해보다가 가중치 구하는게 너무
          힘들어서 클로드한테 부탁해서 따라하고있었습니다.
          결국 stack으로 DFS하나구현하고 그거 복사해서 코드완성 했습니다.
          
*/




int solution(int V, vector<vector<int>>nodes){
    vector<int>visited(V+1);
    tree.push(1);
    int tmp;
    int max_dis=0;
    vector<int>max_len(V+1);
    int max_node=1;
    while(!tree.empty()){
        tmp = tree.top();
        tree.pop();
        if(visited[tmp]>0) continue;
        visited[tmp]++;

        for(int i=1; i<nodes[tmp-1].size(); i+=2){
            if(nodes[tmp-1][i] ==-1)continue;
            int nxt = nodes[tmp-1][i];
            
            if(visited[nxt]!=1){
                tree.push(nxt);
                max_len[nxt]=max_len[tmp]+nodes[tmp-1][i+1];
                if(max_dis<=max_len[nxt]){
                    max_dis=max_len[nxt];
                    max_node = nxt;
                }
            } 
        }
    }


    visited.assign(V+1,0);
    tree.push(max_node);
    max_dis=0;
    max_node=1;
    while(!tree.empty()){
        tmp = tree.top();
        tree.pop();
        if(visited[tmp]>0) continue;
        visited[tmp]++;

        for(int i=1; i<nodes[tmp-1].size(); i+=2){
            if(nodes[tmp-1][i] ==-1)continue;
            int nxt = nodes[tmp-1][i];
            
            if(visited[nxt]!=1){
                tree.push(nxt);
                max_len[nxt]=max_len[tmp]+nodes[tmp-1][i+1];
                if(max_dis<=max_len[nxt]){
                    max_dis=max_len[nxt];
                    max_node = nxt;
                }
            } 
        }
    }
    return max_dis;
}
