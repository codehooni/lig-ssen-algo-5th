#include<string>
#include <iostream>

using namespace std;

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