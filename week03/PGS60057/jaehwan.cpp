// PGS 60057
// 문자열 압축

#include <string>
#include <vector>

using namespace std;
/*
1.  핵심 로직
가설 1:  문자열의 처음부터 (자리수)개의 문자열이 다음 (자리수)개 만큼의 문자열과 같은지 확인하고
        같으면 cnt 축적, 같지 않으면 1개의 문자를 건너 뛰고 다시 반복
        -> 인덱스 처리가 복잡하여 제시간에 끝내지 못함
*/

// -- 2시간 초과 --
int solution(string s) {
    int answer = 0;
    string str = "";
    int len = s.length();
    int half = len / 2;
    int rest = 0;
    for(int digit = 1; digit < half; digit++)
    {
        int idx = 0;
        int cnt = 1;
        string temp = s.substr(idx, digit);
        while(idx <= len - digit*2 + 1)
        {
            if(s.substr(idx + digit, digit) == temp) cnt++;
            else 
            {
                if(cnt - 1) str += temp;
                else 
                {
                    str += (to_string(cnt) + temp);
                    cnt = 1;
                    temp = 
                }
            }
            idx += digit;
        }
    }
    return answer;
}