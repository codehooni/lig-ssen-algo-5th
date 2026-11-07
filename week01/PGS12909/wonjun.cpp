#include<string>
#include <iostream>

using namespace std;

/*
1. 핵심 로직:
    a) [(]의 개수가 [)]의 개수보다 항상 같거나 많아야한다.
    b) 문자열의 종료 시점에서 [(]의 개수와 [)]는 같아야한다.
2. 선택 근거:
    [(] - [)]의 값을 저장하는 cnt 변수를 통해서 시간복잡도 O(N)안에 해결 가능하다.
*/

bool solution(string s)
{
    bool answer = true;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return 0;
    }
    return (!cnt);
}