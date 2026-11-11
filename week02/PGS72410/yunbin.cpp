#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

//알고리즘 자체는 간단하다 해당 문제는 
//c++의 문법을 검색해서 찾아보고 응용해보고자한다.

//이상한 문자들 제거
bool check2(char c){
    switch(c){
        case '-':
        case '_':
        case '.':
            return true;
    }
    //isdigit은 <cctype>내장된 문자가 정수인지 검사해주는 함수
    if((c>=97 && c<=122) || isdigit(c)) return true;
    
    return false;
}

string solution(string new_id) {
    string answer = new_id;
    //<ctype.h>에 속한 c언어의 글로벌 함수 tolower을 호출하기위해 ::사용
    //transform(시작_위치, 끝_위치, 저장할_시작_위치, 변환_함수);
    //1번
    transform(new_id.begin(),new_id.end(),new_id.begin(),::tolower);
    
    // 문자열을 뒤에서부터 지우면 인덱스를 지워도 컨테이너 변경문제가 발생하지 않는다.
    // 2번
    for(int i=new_id.length()-1;i>=0;i--){
        if(!check2(new_id[i]))
            new_id.erase(i,1);
    }
    
    //3번
    for(int i=new_id.length()-1;i>0;i--){
        if(new_id[i]=='.' && new_id[i-1]=='.')
            new_id.erase(i,1);
    }
    //4번
    if(new_id[0] == '.')
        new_id.erase(0,1);
    if(new_id[new_id.length()-1] == '.')
        new_id.erase(new_id.length()-1,1);
    
    //5단계
    if(new_id.length()==0)
        new_id = "a";
    
    //6단계
    if(new_id.length()>=16){
        new_id.erase(15);
        if(new_id[new_id.length()-1] == '.')
            new_id.erase(new_id.length()-1,1);
    }
    //7단계
    if(new_id.length()<=2){
        int len = 3-new_id.length();
        for(int i=0;i<len;i++){
            new_id+=new_id[new_id.length()-1];
        }
    }
    return new_id;
}