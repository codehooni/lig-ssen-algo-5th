#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * 1. 핵심 로직: 기능이 다른 두 개의 Hash table을 활용 
 * 2. 선택 근거: 차가 누적시간을 관리하는 hash table하고 주차장을 관리하는 hash table을 별도로 관리하는 것이 적합할 것이라고 생각하였습니다
 */

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // Step1: unordered_map선언 및 정의
    unordered_map<int,int> park_lot; // 현재 있는 주차장관리하는 Hash table (key: 차 번호, value: 입차 시간 )
    unordered_map<int,int> acc; // 주차 누적시간 관리하는 hash table (Key: 차 번호, value: 주차 누적 시간)
    
    
    // Step 2: 주차 기록 보며 hash table update
    string clock;
    int num;
    string status;
    for (int i=0;i<records.size();i++){
        stringstream ss(records[i]);
        ss>>clock>>num>>status;
        
        int hour = stoi(clock.substr(0,2));
        int minute = stoi(clock.substr(3,2));
        int total_min = hour*60+minute;
        
        if (status=="IN") {
            park_lot[num]=total_min;
        }
        
        else{
            acc[num] += total_min-park_lot[num];
            park_lot.erase(num);
        }
    }
    
    // Step 2-1: 23:59분까지 출차하지 않은 차 반영
    for ( auto& [key, value] : park_lot) {
        acc[key] += 1439 - value;
    }
    
    // Step 3: acc hast table에 누적 시간을 비용으로 치환해서 저장
    for (auto& [key, value] : acc) {
        int total=fees[1];
        if (value>fees[0]){
            total+=ceil((value-fees[0])/(float)fees[2])*fees[3];
        }
        value=total;
        
    }
    
    
    // Step 4: acc의 Key 값의 맞게 Sorting하여 answer.vector의 append
    std::vector<std::pair<int, int>> vec(acc.begin(), acc.end());

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; 
    });
    
    for (int i=0;i<vec.size();i++)
        answer.push_back(vec[i].second);
    
    return answer;
}