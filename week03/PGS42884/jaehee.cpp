#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
1.핵심로직 : 시작점기준으로 내림차순 정렬을 한 후, 시작점이 겹치는 경로는 전부 제거하고,
            겹치지 않는 경로가 나오면 그 경로의 시작점을 기준으로 마저 진행한다.
2.사용근거 : 맨처음에 이해도 못하고있었는데 11/20일날 의찬님이랑 재환님 이야기하시는거 옆에서 듣다가
            문제 대충 이해하고 고민해보는데 끝지점으로 정렬하는것도 까다롭고, 
            생각해보니 아리까리해서 시작지점으로 정렬해서 풀어보면 정렬하는게 조금 더 쉽길래
            쉬울라나? 싶어서 해봤는데 로직자체는 끝지점을 이용하는것과 다를게 없더라구요..
3.시간복잡도 : O(Nlogn)
4.AI사용 : AI로 sort문법 및 제가 생각한 로직이 맞는지 확인 차 AI사용하였습니다.
          AI가 맨처음에 제 로직이 무조건 정답은 보장을 못한다고 하였지만, 한 세번 더 물어보니까 
          맞다곤 하더라구요.. 그리디 로직 특성상 그렇게 말한건진 모르겠지만 나중가선 맞다고하더라구요
*/

int solution(vector<vector<int>> routes) {
    int n = routes.size();
    sort(routes.begin(),routes.end(), greater<vector<int>>());//내림차순 정렬
    int start_p;
    int cnt=1;
    int p=0;
       
        for(int j=1; j<n; ++j){
            start_p = routes[p][0];
            int start = routes[j][0];
            int end = routes[j][1];
            if(start_p>=start&&start_p<=end)continue;
            else{
                cnt+=1;
                p=j;
            }
    }
    
    return cnt;
}