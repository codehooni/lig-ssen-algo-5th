#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
/*

1. 핵심 로직: N개 중에서 K개를 골라야 하므로, 맨 앞의 K+1개 중 하나를 반드시 선택하는 방식 사용
2. 선택 근거: 맨 앞자리가 가장 클 때 가장 큰 수가 보장되므로, 이 과정을 K번 반복해야한다
*/

string solution(string number, int k) {
    string answer = "";
    int rm = k; // 지워야할 남은 숫자
    for (char c : number) {
        while (rm > 0 && !answer.empty() && answer.back() < c) {
            // answer에 number의 맨 앞값을 집어넣고, 현재값이 더 크면 교체한다(최대 k번)
            answer.pop_back();
            rm--;
        }
        // 현재값 추가
        answer.push_back(c);
    }
    // 뒷자리 제
    answer.resize(number.size()-k);
    return answer;
}
