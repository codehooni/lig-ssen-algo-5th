#include <string>
#include <vector>
using namespace std;
// 접근 방식 : 레이저 가동 시간대를 앞선 시간부터 기동하면서 다음 번 드론이 시간대 밖에 있을 경우에만 가동 시간대를 추가하면 최종적인 가동 횟수를 최소화 가능.
// 풀이 로직 : 
// 1. drones를 drones[i][1] 오름차순으로 정렬. 최초 가동 시간대를 [ drones[0][1] , drones[0][1]+d ] 설정.
// 2. drones를 차례대로 탐색하며 j번째 드론이 마지막으로 가동된 k번 시간대 밖에 머무를 경우 (drones[k][1]+d < drones[j][0]) ,
//    신규 가동 시간대 [ drones[j][1] , drones[j][1]+d ] 설정. 가동 횟수 1추가.
// 시간 복잡도 : O(NlogN) - 정렬

bool compare_end(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> drones, int d) {
    int answer=1;
    sort(drones.begin(),drones.end(),compare_end);
    long long last_position=drones[0][1];
    
    for(int i=1;i<drones.size();i++){
        if( (last_position+d < drones[i][0]) ){
            answer+=1;
            last_position = drones[i][1];
        }
    }
    return answer;
}