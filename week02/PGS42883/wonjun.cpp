#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
/*
2 ~ 1,000,000자리 이하의 숫자에서 k개 수를 제거할 때 가장 큰 숫자
최종 숫자는 n - k개가 된다
n C k = (n!) / (k!)(n-k!)
-> 모든 조합을 일일이 비교하는 것은 O(N!)

제거숫자 탐색
3자리에서 1개 제거
abc -> max(ab,bc,ac)가 되게 제거해야함.
ab>bc,ac: a>b>c, bc>ab,ac: b>a, ac>ab,bc: a>c>b
a>b -> b>c면 c제거, b<=c면 b제거
a<b -> a제거
a=b -> (772,227) -> a>c면 c제거, a<=c면 a제거
*/

// number의 맨 앞자리에서 숫자 하나를 제거하여 반환 (최소 3자리)

string solution(string number, int k) {
    string answer = "";
    int rm = k;
    for (char c : number) {
        while (rm > 0 && !answer.empty() && answer.back() < c) {
            answer.pop_back();
            rm--;
        }
        answer.push_back(c);
    }
    answer.resize(number.size()-k);
    return answer;
}