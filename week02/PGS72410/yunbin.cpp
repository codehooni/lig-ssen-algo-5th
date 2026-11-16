/*
 1. 핵심 로직:
    - 문제에서 요구하는 7단계를 순서대로 구현한다.
    - C++의 문자열 관련 문법을 검색하고 응용해보고자 했다.
    - transform, tolower, isdigit, erase 등을 사용했다.

 2. 선택 근거:
    - 문자열 중간의 문자를 제거하면 인덱스가 변경되므로 뒤에서부터 검사한다.
    - erase를 반복해서 사용하므로 최악의 경우 시간복잡도는 O(n²)이다.
*/

#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// 허용되는 문자인지 검사
bool isValidChar(char c){
    switch(c){
        case '-':
        case '_':
        case '.':
            return true;
    }
    // isdigit은 <cctype>에 정의된 숫자 판별 함수
    if((c >= 'a' && c <= 'z') || isdigit(c)) return true;

    return false;
}

string solution(string new_id) {
    // transform(시작 위치, 끝 위치, 저장할 시작 위치, 변환 함수)
    // ::tolower은 전역 함수 tolower을 사용하기 위함
    // 1단계
    transform(new_id.begin(),new_id.end(),new_id.begin(),::tolower);

    // 뒤에서부터 지우면 인덱스가 변경되는 문제를 피할 수 있다.
    // 2단계
    for(int i=new_id.length()-1;i>=0;i--){
        if(!isValidChar(new_id[i]))
            new_id.erase(i,1);
    }

    // 3단계
    for(int i=new_id.length()-1;i>0;i--){
        if(new_id[i]=='.' && new_id[i-1]=='.')
            new_id.erase(i,1);
    }

    // 4단계
    if(!new_id.empty() && new_id[0] == '.')
        new_id.erase(0,1);
    if(!new_id.empty() && new_id[new_id.length()-1] == '.')
        new_id.erase(new_id.length()-1,1);

    // 5단계
    if(new_id.length()==0)
        new_id = "a";

    // 6단계
    if(new_id.length()>=16){
        new_id.erase(15);
        if(new_id[new_id.length()-1] == '.')
            new_id.erase(new_id.length()-1,1);
    }

    // 7단계
    if(new_id.length()<=2){
        int len = 3-new_id.length();
        for(int i=0;i<len;i++){
            new_id+=new_id[new_id.length()-1];
        }
    }
    return new_id;
}