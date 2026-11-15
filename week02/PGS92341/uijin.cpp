#include <string>
#include <vector>
using namespace std;


 // 선택 근거: 차량 번호가 0000~9999 범위이므로 구조체 배열의 인덱스로 활용해 차량 정보를 직접 관리.
 // 핵심 로직: 입출차 기록을 순회하며 차량별 누적 주차 시간을 계산하고, 미출차 차량은 23:59 출차 처리.
 // 차량 번호 순서대로 누적 시간을 조회해 기본요금과 초과요금을 계산.
 // 시간 복잡도: O(N + 10000), N은 입출차 기록의 개수.


// 각 차량에 대한 정보를 담은 구조체 배열(사이즈 10000) 작성.
struct Car{
     int car_number=-1;
     int time=0;
     int total_time=0;
     bool parking_state=false;
};

Car Car_list[10000];

// records의 각 문자열을 읽고 출입 시각, 차량 번호 추출.
void scan_record(string s, int &hour, int &minute,
                 int &car_no) {
    hour = stoi(s.substr(0, 2));
    minute = stoi(s.substr(3, 2));
    car_no = stoi(s.substr(6, 4));
}

// scan_record 실행 후 해당하는 차량번호 xxxx의 정보를 Car_list[xxxx]에 갱신. 출차 상태 여부에 따라 결과를 저장.
void input_car_information(vector<string> records){
    int a,b,c;
    
    for(int i=0;i<records.size();i++){
        scan_record(records[i],a,b,c);
        Car_list[c].car_number=c;
        
        if(Car_list[c].parking_state){
            Car_list[c].total_time+=(60*a+b)-Car_list[c].time;
            Car_list[c].time=0;
            Car_list[c].parking_state=false;
        }
        else{
            Car_list[c].time=(60*a+b);
            Car_list[c].parking_state=true;
        }
    }
}

// 주차 요금표와 총 시각을 입력하면 주차 요금을 반환하는 함수.
int calculating_fee(vector<int> fees,int total_time){
    if (total_time<=fees[0]){return fees[1];}
    else{return fees[1] + fees[3]*(1+ (total_time-fees[0]-1)/fees[2]);
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    input_car_information(records);
    
    for(int i=0;i<10000;i++){
        if(Car_list[i].car_number!=-1){
            // 출차하지 않은 차량은 23:59 출차 처리.
            if (Car_list[i].parking_state) {
                Car_list[i].total_time += 1439 - Car_list[i].time;
                Car_list[i].parking_state = false;
            }
            answer.push_back(calculating_fee(fees,Car_list[i].total_time));
        }
    }
    return answer;
}