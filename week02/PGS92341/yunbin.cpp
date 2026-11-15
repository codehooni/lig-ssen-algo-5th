/*
 1. 핵심 로직:
    - 입차 시간을 저장하고 출차할 때마다 누적 주차 시간을 계산한다.
    - 출차 기록이 없는 차량은 23:59에 출차한 것으로 처리한다.
    - 차량별 누적 시간에 따라 주차 요금을 계산한다.

 2. 선택 근거:
    - 입차 시간은 정렬이 필요하지 않아 unordered_map을 사용한다.
    - 현재 주차 중인 차량은 unordered_set으로 관리한다.
    - 차량 번호 순서대로 출력해야 하므로 map을 사용한다.
    - 추가 요금은 나머지가 있을 경우 올림 처리해야 한다.
*/

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int,string> vehicle_time;
map<int,int> total_time;
unordered_set<int> parked_cars;

// 두 시간의 차이를 분 단위로 계산
int calculate(string time,string st){
    auto pos = st.find(':');
    auto pos2 = time.find(':');
    //stoi 이놈이 아주 효자이다 시간복잡도는 O(n)이니 참고하세용
    int h = stoi(time.substr(0,pos2))-stoi(st.substr(0,pos));
    int m = stoi(time.substr(pos2+1)) - stoi(st.substr(pos+1));

    return h*60 + m;
}

void updateParking(string time,string number,string action){
    if(action=="IN"){
        int num = stoi(number);
        vehicle_time[num] = time;
        parked_cars.insert(num);
    }else{
        int num = stoi(number);
        string st = vehicle_time[num];

        total_time[num] += calculate(time,st);
        vehicle_time[num] = time;
        parked_cars.erase(num);
    }
}

void processRecords(vector<string> records){
    for(const string& s:records){
        auto pos = s.find(' ');
        auto pos2 = s.find(' ', pos + 1);

        string time = s.substr(0, pos);
        string number = s.substr(pos + 1, pos2 - pos - 1);
        string action = s.substr(pos2 + 1);

        updateParking(time,number,action);
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    string t = "23:59";

    processRecords(records);

    // 출차 기록이 없는 차량 처리
    while (!parked_cars.empty()) {
        int num = *parked_cars.begin();
        string cur = vehicle_time[num];

        total_time[num] += calculate(t, cur);

        parked_cars.erase(num);
    }

    // map을 사용했으므로 차량 번호순으로 순회
    for(auto &p:total_time){
        if (p.second <= fees[0]) {
            answer.push_back(fees[1]);
            continue;
        }

        int extraTime = p.second - fees[0];
        int extraFee = ((extraTime + fees[2] - 1) / fees[2]) * fees[3];

        answer.push_back(fees[1] + extraFee);
    }

    return answer;
}