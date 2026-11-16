/*

0. 선택근거
- 차량마다 주차 요금만 있으면 계산하는 것은 쉽다. 
- 차량마다 주차 요금을 알기 위해 정렬을 하고 계산을 생각했다.

1. 아디이어
- carParkingTime에 자동차별 주차 요금을 계산하여 담는다.
    - 주차 요금을 차량별로 하기 위해 차량 번호 기준 정렬을 사용한다.
- parkingTime > baseTime: baseFee + ((parkintTime - baseTime) / unitTime) * unitFee 로 계산

2. 시간복잡도
- O(NlogN), N ≤ 1,000

3. 자료구조
- carParkingTime: vector<int>
- seen: vector<bool>

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<bool> seen(10000, false);
    
    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    
    vector<int> carParkingTime(10000, 0);
    
    sort(records.begin(), records.end(), [](const string& a, const string& b) {
        if(a.substr(6, 4) != b.substr(6, 4)) return a.substr(6, 4) < b.substr(6, 4);
        return a.substr(0, 5) < b.substr(0, 5);
    });
    
    for(int i = 0; i < records.size(); i++) {
        string r = records[i];
        int car = stoi(r.substr(6, 4));
        int inTime = stoi(r.substr(0, 2)) * 60 + stoi(r.substr(3, 2));
        seen[car] = true;
        
        if(i + 1 < records.size() && records[i + 1].substr(6, 4) == records[i].substr(6, 4)) {
            string next = records[i + 1];
            int outTime = stoi(next.substr(0, 2)) * 60 + stoi(next.substr(3, 2));
            carParkingTime[car] += outTime - inTime;
            i++;
        } else {
            carParkingTime[car] += 1439 - inTime;
        }
        
    }
    
    vector<int> ans;
    
    for(int i = 0; i < 10000; i++) {
        if(!seen[i]) continue;
        
        int res = baseFee;
        
        if(carParkingTime[i] > baseTime) {
            res += ((carParkingTime[i] - baseTime + unitTime - 1) / unitTime) * unitFee;
        }
        ans.push_back(res);
    }
    
    return ans;
}