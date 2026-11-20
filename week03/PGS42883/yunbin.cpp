#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// dfs로 진행하였는데 시간초과가 나왔습니다..
// 머리가 굳었는지 썩었는지 도저히 모르겠더군요
// gpt한테 힌트를 받았습니다. 알고리즘에 관해서
// 스택,k의 개수로 지울것들 지워라 뭐 이러더군요
// 생각해보니 앞에 최대한 높은것들을 넣고 뒤는 생각안해도 되겠더군요 
// 아하! 해서 구현해보았습니다
string solution(string number, int k) {
    string result = "";

    for (char c : number) {
        while (!result.empty() && k > 0 && c > result.back()) {
            result.pop_back();
            k--;
        }

        result.push_back(c);
    }

    if (k > 0) {
        result.erase(result.size() - k);
    }

    return result;
}