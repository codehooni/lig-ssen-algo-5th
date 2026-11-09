#include<string>
#include <iostream>

using namespace std;

// 선택 근거: 앞에서부터 괄호의 개수를 카운팅하며 전부 통과하면 성공 처리 가능.
// 핵심 로직: 닫는 괄호가 여는 괄호보다 많아지면 즉시 실패 처리. 순회 종료 후 괄호 개수가 달라도 실패 처리.
// 시간 복잡도: O(N)

bool solution(string s) {
    bool answer = true;
    int num1=0;
    int num2=0;
    
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){num1+=1;}
        if(s[i]==')'){num2+=1;}
        if(num2>num1){
            answer=false;
            break;
        }
    }
    
    if(num1!=num2){
        answer=false;
    }
    
    return answer;
}