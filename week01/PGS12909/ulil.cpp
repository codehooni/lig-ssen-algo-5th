#include <string>

using namespace std;
//1. 핵심 로직: '('면 cnt를 1 올리고 ')'면 1 내려서 괄호 개수를 센다.
//              중간에 cnt가 음수가 되면 ')'가 나온 것이라 바로 false.
//              끝까지 갔을 때 cnt가 0이어야 모든 괄호가 짝지어진 것이다.
//2. 선택 근거: 괄호 종류가 '()' 하나뿐이라 cnt로 0을 맞춰서 결과를 출력했다.

bool solution(string s)
{
    int cnt = 0;

    for (char c : s) {
        if (c == '(') cnt++; // '('
        else cnt--; // ')'

        if (cnt < 0) return false;   // ')'가 더 많아지면 실패
    }

    return cnt == 0;   // 다 끝났을 때 0이면 성공
}
