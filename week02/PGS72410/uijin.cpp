#include <string>
#include <vector>

using namespace std;

 // 선택 근거: 아이디 변환 규칙 7단계를 독립적인 함수로 구현.
 // 핵심 로직: 대문자 변환 → 허용 문자 필터링 → 연속 마침표 제거 → 양끝 마침표 제거
 //            → 빈 문자열 처리 → 길이 제한 → 최소 길이 충족 순서로 문자열 가공.
 // 시간 복잡도: O(N), N은 입력 문자열의 길이.


// 1단계 : 아스키 코드가 대문자인 문자가 있으면 소문자로 치환.
string stage1(string new_id){
    for(int i=0;i<new_id.size();i++){
        if( (0<=new_id[i]-'A') && (new_id[i]-'A'<=25) ){
            new_id[i]+=32;
        }
    }
    return new_id;
}

// 2단계 : 각 자리를 탐색하며 기준 통과한 문자만 신규 문자열에 추가해서 결과 반환.
string stage2(string new_id){
    string answer="";
    for(int i=0;i<new_id.size();i++){
        if( islower(new_id[i]) || isdigit(new_id[i]) || (new_id[i]=='-') || (new_id[i]=='_') || (new_id[i]=='.') ){
            answer+=new_id[i];
        }
    }
    return answer;
}

// 3단계 : 공백 상태면 그대로 반환. 앞자리와 현재 자리가 마침표면 패스하고, 그 외인 문자만 신규 문자열에 추가하며 반환.
string stage3(string new_id){
    if (new_id.empty()) return new_id;
    
    string answer="";
    answer+=new_id[0];
    for(int i=1;i<new_id.size();i++){
        if( (new_id[i-1]=='.') && (new_id[i]=='.') ){
            continue;
        }
        else{answer+=new_id[i];}
    }
    return answer;
}

// 4단계 : .front() 하고 .back() 사용 결과가 마침표일 경우 나머지 문자열 반환.
string stage4(string new_id) {
    if(new_id.empty()){return new_id;}
    if(new_id.front()=='.'){
        new_id=new_id.substr(1,new_id.size()-1);
    }
    
    if(new_id.empty()){return new_id;}
    if(new_id.back()=='.'){
        new_id=new_id.substr(0,new_id.size()-1);
    }
    return new_id;
}

// 5단계. 빈 문자열이면 "a" 반환.
string stage5(string new_id){
    if(new_id.empty()){new_id="a";}
    return new_id;
}

// 6단계
string stage6(string new_id){
    if(new_id.size()>=16){
        new_id=new_id.substr(0,15);
    }
    if(new_id.back()=='.'){
        new_id=new_id.substr(0,new_id.size()-1);
    }
    
    return new_id;
}

// 7단계.
string stage7(string new_id){
    while(new_id.size()<3){
        new_id=new_id+new_id.back();
    } 
    return new_id;
}

string solution(string new_id) {
    new_id=stage1(new_id);
    new_id=stage2(new_id);
    new_id=stage3(new_id);
    new_id=stage4(new_id);
    new_id=stage5(new_id);
    new_id=stage6(new_id);
    new_id=stage7(new_id);
    
    return new_id;
}