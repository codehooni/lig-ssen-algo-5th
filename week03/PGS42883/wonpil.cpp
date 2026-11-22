#include <bits/stdc++.h>


//핵심로직:앞의 자리에 더 작은 숫자가 있으면 제거 
//선택근거:완전탐색을 하기에는 입력의 크기가 최대 1,000,000 이기 때문에 크다 판단.
//테스트 케이스에서 앞의 자리에 더 작은 숫자를 제거하는 규칙을 발견 
//위의 경우를 지킬경우 항상 최적해를 제공한다 판단.
//시간복잡도:O(N)


using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(char num: number){
        //앞서 추가했던 숫자(더 큰자리의 수)가 현재 선택된 숫자보다
        //작다면 제거하고 k -= 1
        while(k > 0 && !answer.empty() && (answer.back() < num) ){
            answer.pop_back();
            k--;
        }
        answer.push_back(num);
    }
    
    //내림차순으로 정렬돼 있는 경우 k개 제거가 되지 않게 됨
    //이 경우 남은 k개 만큼 아래자릿수에서 제거해줌
    while (k > 0) {
        answer.pop_back();
        k--;
    }

    return answer;
}