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
1. 핵심 로직: 차량번호별로 출입 내역을 unordered_map으로 저장하고, 각 차량별로 요금 책정
2. 선택 근거: 차량들은 반드시 먼저 입차하므로, "입차"/"출차" 내역에 상관없이 홀짝 인덱스로 접근하여 출차여부를 확인하면 된다.

시간복잡도: [차량번호별 시간] 정렬에서 O(N * logN)
*/

// 요금기준 (fees[0] ~ fees[3])
// 1) ~ [0]m = [1]
// 2) [0]m+  = [1] + [3] * ((t-[0]+[2]-1)/[2])  -> 올림 계산용
int getMoney(vector<int> fees, int time) {
    int result = fees[1];
    // 기준시간 이내: 기본요금
    if (time <= fees[0]) return result;
    // 기준시간 초과: 추가요금 (올림)
    int overtime = time - fees[0] + fees[2] - 1;
    // 기준시간 초과 책정: 기본요금 + 추가시간 요금
    result += fees[3] * (overtime / fees[2]);
    return result;
}
// pair<int,int>에 대해서, 첫 요소(=차량번호) 작은 순으로 정렬하는 방법
bool cmp (pair<int,int> a, pair<int,int> b) {
    return (a.first < b.first);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int, vector<int>> vlist;   // 차량별 방문시간 목록
    
    for (string r : records) {
        // 차량번호별로 출입기록 작성
        stringstream rr(r);
        // vnum = 차량번호, h = 시간, m = 분
        int vnum, temp2, h, m;
        char colon;
        // [ : ]로 시간과 분을 구분지어 입력받음.
        rr >> h >> colon >> m >> vnum >> temp2;
        // 분단위로 시간 기록
        int time = h * 60 + m;
        // 신규 차량일경우 새로운 벡터 등록
        if (vlist.find(vnum) == vlist.end()) vlist[vnum] = {time};
        // 기록이 있는 차량이면 기록만 추가
        else vlist[vnum].push_back(time);
    }
    vector<pair<int,int>> pricelist;    // 차량 번호 별 시간 벡터
    for (auto v : vlist) {
        // 입차가 더 많은 경우 23:59에 출차기록 추가
        if (v.second.size()&1) v.second.push_back(1439);
        // 시간기록의 [홀수 - 짝수] 값 저장
        int time = 0;
        // 입/출차 쌍별로 시간 계산 (짝수 = 입차, 홀수 = 출차)
        for (int i = 0; i < v.second.size(); i++) {
            time += (i&1) ? v.second[i] : -v.second[i];
        }
        pricelist.push_back({v.first, getMoney(fees, time)});
    }
    // id순 정렬
    sort(pricelist.begin(), pricelist.end(), cmp);
    for (auto p : pricelist) {
        answer.push_back(p.second);
    }
    return answer;
}