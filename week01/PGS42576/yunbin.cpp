#include <string>
#include <vector>
#include <map>
using namespace std;

/**
    1. 핵심 로직:
    - 동일한 이름이 여러번 등장할 수 있다. 이를 map을 이용하여 string과 int를 key와 value로 하여 
      map에 저장하고 participant를 돌면서 completion에 없는 사람을 찾는다.
    2. 선택 근거: 
    - 각 이름에 등장 횟수를 세야하기에 map을 이용하였다 하지만 c++에서의 map은 
      약 O(logn)으로 동작하기에 추후 unordered_map을 이용하여 O(1)로 동작하도록 개선할필요가있다.
      물론 unordered_map은 해시함수를 이용하기에 최악의 경우 O(n)으로 동작할 수 있다.
 */

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> map;
    for(string s:completion){
        map[s]++;
    }
    for(string s:participant){
        if(map[s]==0)
            return s;
        map[s]--;
    }
    return answer;
}