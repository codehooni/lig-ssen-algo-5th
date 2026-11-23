#include <string>
#include <vector>
using namespace std;

// 알고리즘 선택 이유 : 문자열의 길이가 1000 이하이므로 완전탐색으로 모든 길이에 대해 탐색. 
// 풀이 로직.
// 1. 문자열 s를 제일 앞부터 n개 단위로 압축할 시 전체 길이를 반환하는 함수 pressed_length 작성.
// 2. 시작점에서 파편을 작성. 마지막에 제작된 파편과 다음 번 파편을 비교.
// 동일 문자열일 경우 연속 개수 +1. 다른 문자열일 경우, (해당 문자열 길이)+(연속 개수 값을 문자열로 변환한 후의 길이)를 전체 길이에 추가. 
// 만들 수 있는 모든 파편에 대해 위 과정 반복. 파편이 되지 못한 나머지는 그 길이를 추가.
// s에 대하여 작성 가능한 모든 파편 개수(1 ~ s.size()/2 )에 대해 pressed_length 탐색해서 최소 길이 반환. 
// 시간 복잡도 : O(N^2)

int pressed_length(string s,int n){
    int length=0;
    string last_string=s.substr(0,n);
    int piece_counter=1;
    int a=n;
    
    while(a+n<=s.size()){
        string current_string=s.substr(a,n);
        // 직전의 문자열 파편과 다를 경우
        if( last_string!=current_string ){
            last_string=current_string;
            length+=(piece_counter==1? n: n+to_string(piece_counter).size() );
            piece_counter=1;
        }
        // 직전의 문자열 파편과 동일한 경우
        else{
            piece_counter+=1;
        }
        a+=n;
    }
    // 신규 파편 작성 불가시, 마지막 파편에 대해서도 처리.
    length+=(piece_counter==1? n: n+to_string(piece_counter).size() );
    // 파편이 되지 못한 나머지 길이 추가.
    length+=s.size()%n;
    
    return length;
}

int solution(string s) {
    int answer = s.size();
    
    for(int i=1;i<=s.size()/2;i++){
        int a=pressed_length(s,i);
        if(a<answer){
            answer=a;
        }
    }
    return answer;
}