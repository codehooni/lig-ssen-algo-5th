
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
1. 핵심 로직
    1. 문자열을 앞에서부터 순회하면서 큰 숫자가 앞에 오도록 한다.
    2. 현재 숫자가 이전 숫자보다 크다면 이전 숫자를 제거한다.
       이때 k가 남아 있는 경우에만 제거할 수 있다.
    3. 문자열을 스택처럼 활용해 마지막 숫자와 비교하고,
       조건에 맞으면 pop_back()으로 제거한다.
    4. 모든 숫자를 확인한 후에도 k가 남아 있다면
       문자열 뒤에서 남은 개수만큼 제거한다.

2. 선택 근거
    처음에는 DFS로 모든 경우의 수를 탐색하려고 했습니다.
    그런데 시간 초과가 나왔습니다.

    머리가 굳었는지 썩었는지 도저히 모르겠더군요.
    그래서 GPT한테 알고리즘에 대한 힌트를 받았습니다.

    스택을 사용하고, k의 개수만큼 숫자를 제거하라는 힌트였습니다.

    처음에는 이게 무슨 말인가 싶었는데,
    생각해보니 앞에 최대한 큰 숫자들을 배치하면
    뒤에 있는 숫자는 상대적으로 덜 중요하겠더군요.

    아하! 그러면 현재 숫자가 이전 숫자보다 클 때
    이전 숫자를 제거하면 되겠다는 생각이 들었습니다.

    굳이 stack 자료구조를 사용할 필요 없이
    string의 back()과 pop_back()을 사용하면
    동일한 방식으로 구현할 수 있겠더군요.

    다만 모든 숫자가 내림차순으로 되어 있다면
    제거할 숫자가 남을 수 있으므로
    마지막에 남은 k개를 뒤에서 제거하도록 구현했습니다.

3. AI 활용
    DFS에서 시간 초과가 발생하여 GPT에게 알고리즘 힌트를 받았습니다.
    스택을 활용하고 k개만큼 숫자를 제거하는
    그리디 방식에 대한 힌트를 참고했습니다.
*/

string solution(string number, int k)
{
    string result = "";

    for (char c : number)
    {
        while (!result.empty() && k > 0 && c > result.back())
        {
            result.pop_back();
            k--;
        }

        result.push_back(c);
    }

    if (k > 0)
    {
        result.erase(result.size() - k);
    }

    return result;
}
