#include <string>
#include <vector>

using namespace std;

/*
1. 핵심로직: 높은 자리 숫자부터 하나씩 내려오면서 각 자리마다 최대한 큰 수를 선택한다. (그리디)
            다만, 모든 숫자를 탐색할 필요는 없고, 골라야 하는 자릿수 이상인 숫자에 대해서만 탐색을 하면 된다.
            또한, 앞의 선택에 따라 범위가 조정되므로 그 부분을 고려해서 작성한다.
            
2. 선택근거: 그리디 알고리즘이므로 가장 단순히 큰 수를 큰 자리 수에서 가져가면 되지 않을까 생각했고, 몇 가지 제한조건만 지키면
            논리적으로 문제가 없는 것으로 보여 해당 방식으로 접근했다.
*/

/*
1. k개의 수를 제거했을 때 얻을 수 있는 가장 큰 수
2. k가 주어짐.
3. k는 1이상 number의 자릿수 미만

어떤 규칙이 있을지 생각해보자
K는 최대 6
*/

// 코드 조금 더 최적화 해보기

typedef struct _max_val
{
    char val;
    int idx;
} max_val;

string solution(string number, int k) {
    int last_pick = -1;
    int len = number.length();
    int diff = len - k;

    string answer;

    for (int i = 0; i < diff; ++i)
    {
        max_val a = (max_val){0, 0};

        for (int j = last_pick + 1; j <= k + i; ++j)
        {
            if (number[j] > a.val)
            {
                a.val = number[j];
                a.idx = j;
            }
        }
        last_pick = a.idx;
        answer += a.val;
    }
    
    return answer;
}
