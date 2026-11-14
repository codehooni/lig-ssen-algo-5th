/*

0. 선택근거
- 단순 구현 문제이다. 문자열을 위한 함수를 잘 이용해서 풀어보기.

1. 아이디어
    1. tolower() 사용
    2. if ! @ # *: erase() 사용
    3. for all character: .갯수 세서 첫번째만 남기고 erase()
    4. front(), back() == '.': erase()
    5. .size() == 0: a 대입
    6. .size() >= 16: 첫 erase(begin(), begin() + 15) .이 멘마지막에 있는지도 확인 후 erase()
    7. .size() < 3: new_id += new_id.back() 반복

2. 시간복잡도
- O(N) , N < 1,000

3. 자료구조


*/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string new_id) {
    
    for(auto& c : new_id) c = tolower(c);
    
    for(int i = 0; i < new_id.size();) {
        char c = new_id[i];
        if(!(islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.')) new_id.erase(i, 1);
        else i++;
    }
    
    for(int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        int cnt = 0;
        if(c == '.') {
            while(new_id[i + 1 + cnt] == '.') cnt++;
            new_id.erase(i + 1, cnt);
        }
    }
    
    if(!new_id.empty() && new_id.front() == '.') new_id.erase(0, 1);
    if(new_id.size() == 0) new_id = "a";
    
    if(new_id.size() >= 16) new_id.erase(15);
    while(!new_id.empty() && new_id.back() == '.') {
        new_id.pop_back();
    }
    while(new_id.size() <= 2) new_id.push_back(new_id.back());
    
    cout << "\"" << new_id << "\"" << endl;
    
    return new_id;
}