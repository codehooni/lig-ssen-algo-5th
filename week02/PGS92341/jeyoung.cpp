#include <string>
#include <vector>
#include <map>
using namespace std;

int getCar(char a, char b, char c, char d) {  //차량번호 구하는 함수
    return 1000 * (a - '0') + 100 * (b - '0') + 10 * (c - '0') + (d - '0');
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, pair<int, int>> m;
    //IN일 경우에 맵에 key=차량번호, value = {시간,등장횟수}, 시간에 -time 누적
    //Out일 경우에 맵에 key=차량번호, value = {시간,등장횟수}, 시간에 +time 누적
    //등장횟수가 홀수인 경우에는 입차하고 출차하지 않은 차가 있는것이므로 23*60 + 59를 시간에 더해준다
    //map 이므로 키값인 차량번호 순서대로 정렬되어있다 따라서 map를 순서대로 순회하면서 answer에 push_back하기
    for (int i = 0;i < records.size();i++) {
        int time = 0;
        time += ((records[i][0] - '0') * 10 + records[i][1] - '0') * 60;
        time += ((records[i][3] - '0') * 10 + records[i][4] - '0');
        int num = getCar(records[i][6], records[i][7], records[i][8], records[i][9]);

        if (records[i][11] == 'I') {  //in 일떄
            if (m.find(num) == m.end()) {
                m[num] = { time * -1,1 };
            }
            else {
                m[num] = { m[num].first - time,m[num].second + 1 };
            }
        }
        else {  //out 일때
            m[num] = { m[num].first + time,m[num].second + 1 };
        }
    }

    for (const auto& [key, value] : m) {  //이 부분 공부 필요, 맵 순회 더 좋은방법 있을까?
        int cost = value.first;
        if (value.second % 2 != 0) {
            cost += (23 * 60 + 59);
        }
        int a = 0;
        if (cost >= fees[0]) {
            a += fees[1]; cost -= fees[0];
            if (cost % fees[2] != 0) {
                a += ((cost / fees[2]) + 1) * fees[3];
            }
            else {
                a += (cost / fees[2]) * fees[3];
            }
        }
        else {
            a = fees[1];
        }
        answer.push_back(a);
    }

    return answer;
}