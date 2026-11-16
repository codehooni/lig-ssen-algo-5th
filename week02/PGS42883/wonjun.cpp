#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
/*
2 ~ 1,000,000자리 이하의 숫자에서 k개 수를 제거할 때 가장 큰 숫자
최종 숫자는 n - k개가 된다
앞자리가 최대가 되어야 가장 크므로, 맨 앞의 k+1개 중 가장 큰 값부터 answer에 추가한다.
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
    // 7654321 처럼 내림차순이면 뒷자리 제거
    answer.resize(number.size()-k);
    return answer;
}