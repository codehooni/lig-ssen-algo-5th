#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//맵 두개면 이쁘게 가능할거같은데요
//자동차 시간은 정렬이 필요하지않으므로 unordered사용
unordered_map<int,string> vehicle_time;
map<int,int> total_vehicle; 
unordered_set<int> vehicle_in;
int calculate(string time,string st){
    auto pos = st.find(':');
    auto pos2 = time.find(':');
    int h = stoi(time.substr(0,pos2))-stoi(st.substr(0,pos));
    int m = stoi(time.substr(pos2+1)) - stoi(st.substr(pos+1));
    return h*60 + m;
}
void InAndOut(string time,string number,string action){
    if(action=="IN"){
        int num = stoi(number);
        vehicle_time[num] = time;
        vehicle_in.insert(num);
    }else{
        int num = stoi(number);
        string st = vehicle_time[num];
        total_vehicle[num] += calculate(time,st);
        vehicle_time[num] = time;
        vehicle_in.erase(num);
    }
}
void record(vector<string> records){
    for(const string& s:records){
        auto pos = s.find(' ');
        auto pos2 = s.find(' ', pos + 1);

        string time = s.substr(0, pos);
        string number = s.substr(pos + 1, pos2 - pos - 1);
        string action = s.substr(pos2 + 1);
        InAndOut(time,number,action);
        
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    string t = "23:59";
    
    record(records);
    while (!vehicle_in.empty()) {
        int num = *vehicle_in.begin();
        string cur = vehicle_time[num];

        total_vehicle[num] += calculate(t, cur);

        vehicle_in.erase(num);
    }
    for(auto &p:total_vehicle){
        cout << "first: " << p.first << " second: "<<p.second << endl;
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