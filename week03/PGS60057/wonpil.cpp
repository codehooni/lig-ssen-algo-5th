#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//핵심 로직: 완전탐색을 하며 최소길이 갱신
//선택 근거: 
//1. 입력의 크기가 작았다
//2. 모든 부분문자열의 경우를 탐색할 필요가 있다 생각했다.
//시간 복잡도: O(N^2)


//1. 이중반복문을 사용 
//2. 첫 반복문에서 문자열의 크기(윈도우)를 결정
//3. 안쪽 루프에서 문자열길이/윈도우 만큼 문자열 성형
//3-1. 그 다음에오는 부분문자열이 같으면 cnt+1
//3-2. 다르면 기존의 cnt+부분문자열로 문자열을 업데이트하고 앞으로 진행될
//부분문자열을 바꿈
//3-3.안쪽 반복문을 돌고 만들어진 문자열에 나머지 문자열이 있으면 이를 더함
//4. 기존의 최소길이 문자열길이와 비교후 갱신

int func(const string& s, int len){
    int min_len = len;
    int cnt, j;
    for(int window = 1; window <= len; window++){
        string sub_s = s.substr(0,window);
        string new_s = "";
        cnt = 1;
        for(j = window; j <= len ; j += window){
            string comp_s =s.substr(j,window);
            if(sub_s == comp_s) cnt++;
            else{
                if(cnt > 1) new_s += (to_string(cnt)+sub_s);
                else new_s += sub_s;
                sub_s = comp_s;
                cnt = 1;
            }   
        }
        new_s += s.substr((j-window));
        min_len = min(min_len, (int)new_s.length());  
    }
    return min_len;
}

int solution(string s) {
    int len = s.length();
    return func(s, len);
}