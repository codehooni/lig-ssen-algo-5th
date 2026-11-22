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
int solution(string s) 
{
    int len = s.length();
    int answer = len;                        // 압축 안 했을 때가 최댓값

    for (int digit = 1; digit <= len / 2; digit++) 
    {
        string result = "";
        string prev = s.substr(0, digit);    // 비교 기준이 되는 앞 조각
        int cnt = 1;

        for (int i = digit; i < len; i += digit) 
        {
            string cur = s.substr(i, digit);

            // compare는 같으면 0 → "== 0"이 "같다"는 뜻
            if (cur.compare(prev) == 0) 
            {
                cnt++;
            } 
            else 
            {
                if (cnt > 1) result += to_string(cnt);
                result += prev;
                prev = cur;
                cnt = 1;
            }
        }
        // 마지막 조각 처리
        if (cnt > 1) result += to_string(cnt);
        result += prev;

        answer = min(answer, (int)result.length());
    }
    return answer;
}
