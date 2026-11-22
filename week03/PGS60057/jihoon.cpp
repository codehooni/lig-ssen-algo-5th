/*

0. 선택근거
- 

1. 아디이어
- 우선 어떤 방법이 좋을지 모르니 다 해본다. (1 ~ N/2)
- 문자열을 k만큼 읽고 뒤에 k만큼 잘라서 비교한다. (N)
- 달라지는 문자열이 나오면 숫자와 함께 저장 (단, 1일때는 숫자 없이)

2. 시간복잡도
- O(N^2): N^2 ⩽ 1,000,000

3. 자료구조
- cmp: string
- res: string

*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 10000;
    int len = s.size();
    
    if(s.size() == 1) return 1;
    
    for(int k = 1; k <= len / 2; k++) {
        
        int cnt = 1;
        string cmp = s.substr(0, k);
        string res = "";
        
        for(int i = k; i <= len; i += k) {
            string next = s.substr(i, k);
            if(next == cmp) cnt++;
            
            else {
                // 문자열에 추가
                if(cnt > 1) res += to_string(cnt);
                res += cmp;
                
                // 다음 문자열 저장
                cmp = next;
                cnt = 1;
            }
        }
        if(cnt > 1) res += to_string(cnt);
        res += cmp;
        
        // cout << res << endl;
        answer = min(answer, (int) res.size());
    }
    
    return answer;
}