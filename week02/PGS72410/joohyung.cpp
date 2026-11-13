#include <string>
#include <vector>

using namespace std;
/**
 * 1. 핵심 로직: Programmers에서 기술한 순서대로 문자열 수정을 진행한다 for문으로 문자열 완전 탐색을 진행한다
 * 2. 선택 근거: 
 */

string solution(string new_id) {
    string answer = "";
    
    
    // Step1: new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    for (int i=0;i<new_id.length();i++) {
        if ('A'<=new_id[i]&&new_id[i]<='Z') {
            new_id[i]+=32;
        }
    }
    
    //Step2: new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    char tmp;
    for (int i=0;i<new_id.length();i++) {
        tmp=new_id[i];
        if(!isdigit(tmp) && !isalpha(tmp) && tmp != '-' && tmp !='_' &&tmp != '.')
        {
            new_id.erase(i,1); 
            i--; // index matching
        }
    }
    
    // Step3: new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    char prev=new_id[0];
    char cur;
    for (int i=1;i<new_id.length();i++) {
        cur = new_id[i];
        if (prev=='.' && cur==prev){
            new_id.erase(i,1);
            i--;
        }
        prev=cur;
    }
    
    // Step 4:new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if (new_id[0]=='.')
    {
        new_id.erase(0,1);
    }
    
    if (new_id.back()=='.') {
        new_id.pop_back();
    } 
    
    // Step 5: new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if (new_id.empty())
        new_id="a";
    
    // Step 6: new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if (new_id.length()>=16)
    {
        new_id=new_id.substr(0,15);
        if (new_id.back()=='.')
        {
            new_id.pop_back();
        }
    }
    
    if (new_id.length()<=2){
        char tmp=new_id.back();
        while(new_id.length()<3)
        {
            new_id.push_back(tmp);
        }
    }
        
    return new_id;
}