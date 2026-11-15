#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/*
    시간 복잡도: O(N^2) - 입력 파싱이 O(N^2)정도 예상, 나머지 처리 로직 O(N)
    접근 방식: 시간을 분으로 변환한 후 입출 여부에 따라 각 주차 시간을 누적하고 요금을 계산함
    선택 근거: 2가지 방식을 생각했고 해시테이블(unordered_map)과 균형이진트리(set)를 활용함
        1. 스택 - 차량 번호, 시간 순으로 오름차 정렬하고 입출 여부에 따라 스택에 넣고 빼며 누적 시간을 계산하는 방식
            (조건 처리가 복잡해질 것 같았음)
        2. 해시테이블 & 균형이진트리
            a. 차량 번호의 오름차순을 맞추기 위해 set 활용
            b. 모든 차량의 누적 시간을 O(N)으로 구하기 위해 unordered_map 활용
    핵심 로직:
        1. 차량 번호를 오름차로 저장해놓고 해시테이블을 활용해 각 차량의 주차 시간을 누적
        2. 차량 번호 순서대로 주차 시간을 비용으로 변환
 */

#define MAX_TIME 60 * 23 + 59

vector<string> split(const string& input, string delimiter) {
    vector<string> ret;
    long long start = 0, end;
    
    while ((end = input.find(delimiter, start)) != string::npos) {
        ret.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
    }
    
    ret.push_back(input.substr(start));
    return ret;
}

int toNum(const string& input) {
    return atoi(input.c_str());
}

int getMin(const string& time) {
    vector<string> t = split(time, ":");
    return toNum(t[0]) * 60 + toNum(t[1]);
}

int getCost(const int time, const vector<int>& fees) {
    int bTime = fees[0], bFee = fees[1], uTime = fees[2], uFee = fees[3];
    if (time < bTime) return bFee;
    return bFee + (((time - bTime + uTime - 1) / uTime) * uFee);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<tuple<int, int, int>> parsed;
    unordered_map<int, int> temp, time;
    set<int> nums;
    
    for (string record : records) {
        vector<string> r = split(record, " ");
        int num = toNum(r[1]);
        parsed.push_back(make_tuple(num, getMin(r[0]), r[2] == "IN" ? 1 : 0));
        nums.insert(num);
    }
    
    for (auto [num, ctime, isIn] : parsed) {
        if (isIn) temp[num] = ctime;
        else {
            time[num] += ctime - temp[num];
            temp.erase(num);
        }
    }
    
    for (auto [num, ctime] : temp) {
        time[num] += MAX_TIME - ctime;
    }
    
    for (auto num : nums) {
        answer.push_back(getCost(time[num], fees));
    }
    
    return answer;
}