#include <string>
#include <vector>
#include <map>

using namespace std;

//1. 핵심 로직: IN이면 들어온 시각을 inTime에 적어 두고, OUT이면 (나간 시각 - 들어온 시각)을                 total에 더한다.
//              시각은 "시 × 60 + 분"으로 바꿔서 숫자끼리 뺄 수 있게 한다.
//              나간 차는 inTime에서 지워서, 끝까지 남은 차를 23:59에 나간 걸로 계산한다.
//              누적 시간이 기본 시간을 넘으면, 넘은 시간을 단위 시간으로 나누고 나머지가 있                 으면 1을 더해(올림) 요금을 계산한다. 올림으로 요금 계산하는 법은 AI를 활용해
//              작성하였다.
//2. 선택 근거: 정답을 차량번호 작은 순서로 내야 해서, 키가 자동으로 오름차순 정렬되는 map을                   썼다.
//              한 차가 여러 번 들락날락할 수 있어서 total에 =가 아니라 +=로 누적했다.
    
vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> inTime;    // 차량번호 → 들어온 시각
    map<string, int> total;     // 차량번호 → 누적 주차 시간

    for (string r : records) {
        // ex) "05:34 5961 IN" 을 잘라서 읽기
        int time = stoi(r.substr(0, 2)) * 60 + stoi(r.substr(3, 2));
        string car = r.substr(6, 4);
        string type = r.substr(11);

        if (type == "IN") {
            inTime[car] = time;
        } else {
            total[car] += time - inTime[car];
            inTime.erase(car);         
        }
    }

    // 안 나간 차는 23:59에 나간 걸로 계산
    for (auto p : inTime) {
        total[p.first] += 23 * 60 + 59 - p.second;
    }

    vector<int> answer;
    for (auto p : total) {             
        int t = p.second;
        int fee = fees[1];             
        if (t > fees[0]) {
            int over = t - fees[0];
            int units = over / fees[2];           
            if (over % fees[2] != 0) units++; //나머지가 있으면 1 더하기(올림)(AI 활용)
                fee += units * fees[3];
        }
        answer.push_back(fee);
    }
    return answer;
}
