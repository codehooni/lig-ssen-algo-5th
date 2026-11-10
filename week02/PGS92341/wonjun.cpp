#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

/*
1. 핵심 로직: 차량번호, 내역에 따른 
2. 선택 근거: 
*/

// 요금기준 (fees[0] ~ fees[3])
// 1) ~ [0]m = [1]
// 2) [0]m+  = [1] + [3] * ((t-[0]+[2]-1)/[2])
int getMoney(vector<int> fees, int time) {
    int result = fees[1];
    // 기준시간 이내: 기본요금
    if (time <= fees[0]) return result;
    // 기준시간 초과: 추가요금 (올림)
    int overtime = time - fees[0] + fees[2] - 1;
    result += fees[3] * (overtime / fees[2]);
    return result;
}
bool cmp (pair<int,int> a, pair<int,int> b) {
    return (a.first < b.first);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int, vector<int>> vlist;   // 차량별 방문시간 목록
    
    for (string r : records) {
        // 차량번호별로 출입기록 작성
        stringstream rr(r);
        int vnum, stot, temp2, h, m;
        char colon;
        rr >> h >> colon >> m >> vnum >> temp2;
        int time = h * 60 + m;
        // 신규 차량일경우 등록
        if (vlist.find(vnum) == vlist.end()) vlist[vnum] = {time};
        // 이전 차량이면 기록만 추가
        else vlist[vnum].push_back(time);
    }
    vector<pair<int,int>> pricelist;
    for (auto v : vlist) {
        // 입차가 더 많은 경우 23:59에 출차기록 추가
        if (v.second.size()&1) v.second.push_back(1439);
        // 시간기록의 [홀수 - 짝수] 값 저장
        int time = 0;
        for (int i = 0; i < v.second.size()/2; i++) {
            time += v.second[i*2 + 1] - v.second[i * 2];
        }
        pricelist.push_back({v.first, getMoney(fees, time)});
    }
    // id순 정렬
    sort(pricelist.begin(), pricelist.end(), cmp);
    for (auto p : pricelist) {
        //cout << p.first << ": " << p.second << endl;
        answer.push_back(p.second);
    }
    return answer;
}