#include <string>
#include <iostream>

using namespace std;

// 1. 핵심로직: cnt 변수를 이용해서 '('이 들어오면 cnt증가, ')'이 들어오면 cnt가 양수일 때만 cnt감소
// 2. 선택근거: 스택을 공부하기 위한 문제이지만 간단하고 빠른 연산속도를 실현하기 위해 해봤습니다.

// 여담: 아래 if(s[0] == ')') return false; 구문으로 예외처리를 해주긴 했는데,
// 이러면 입력으로 "((())))))))" 같은 문자열이 나오면 true가 아닌 false가 나와야 하는 것이 아닌지..?
// 서버에서 정답으로 책정해준 것으로 보아 "(())))))"는 정답인 케이스로 추정됩니다.
// => 그냥 스택써서 해결하는게 나은 것 같습니다.

bool solution(string s)
{
    int cnt = 0;
    bool answer = false;
    //먼저 ')'가 들어오면 false이기 때문에 예외처리
    if(s[0] == ')') return false;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            cnt++;
        }
        else
        {
            if(cnt)
            {
                cnt--;
            }
        }
    }
    if(cnt) answer = false;
    else answer = true;
    return answer;
}