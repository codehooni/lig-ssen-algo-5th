#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// PGS 42576
// 1. 핵심 로직: 완전 탐색 하면서 완주한 선수들을 찾아서 순차적으로 소거하고 남는 선수 1명 리턴
// 2. 선정 이유: 해시 자료구조를 이용하면 완주한 선수들을 찾고 소거하는 과정이 O(1)이기 때문에

string solution(vector<string> participant, vector<string> completion) {
    //같은 선수가 중복되어 존재할 수 있기 때문에 multiset STL을 사용
    unordered_multiset<string> _par;
    for(int i = 0; i < participant.size(); i++)
    {
        //multiset에 선수들을 전부 집어넣음
        _par.insert(participant[i]);
    }
    for(int i = 0; i < completion.size(); i++)
    {
        //완주한 선수들을 찾아서 _par에서 없앰
        //해시 자료구조이기 때문에 find, erase, find 모두 O(1)임.
        //_par.find(completion[i])의 경우 리턴값이 iterator이기 때문에 *을 붙여서
        //최종적으로 rvalue를 string으로 만들기
        if(completion[i] == *(_par.find(completion[i]))) 
            _par.erase(_par.find(completion[i]));
    }
    return *(_par.begin());
}