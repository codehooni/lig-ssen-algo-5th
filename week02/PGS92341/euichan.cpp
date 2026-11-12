#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/*
* 1. 핵심 로직: sstream 라이브러리에 있는 stringstream 클래스를 활용해서 get 라인으로 공백과 ':'을 기준으로 문자열을 분리하여
*              해쉬테이블에 임시로 출차시간과 입차시간의 차이를 저장한다. 자동차의 번호를 오름차순으로 정렬하기 위해 set 클래스를 활용해 저장했다.
*
* 2. 선택 근거: 문자열의 요소를 하나하나 순환하며 공백과 ':'를 찾아서 파싱하는 것보다 stringstream을 활용하는 편이 코드가 짧을 것이라고 판단했다.
*              문자열에 대응하는 숫자를 저장하는데에는 해쉬테이블이 접근이 빠를 것으로 판단해 unordered map을 활용했고, 해쉬테이블 자체는 인덱스를 알 수 없기에
*              자동차 번호를 오름차순으로 정렬할 겸, 인덱스를 저장할 겸 set을 활용했다.
*/

/*
1. 요금표, 차량 입출차 기록
2. 차량 별 주차 요금 계산
3. 기본 시간 이하 -> 기본 요금
4. 기본 시간 초과 -> 기본 요금 + 단위시간마다 단위요금 (올림)
*/

unordered_map<string, int> car_in_out;
unordered_map<string, int> val;

set<string> car_names;

void CalculateTime(vector<string> &r)
{
    for (int i = 0; i < r.size(); i++)
    {
        stringstream ss(r[i]);
        
        string token;
        int num = 0;
        int cnt = 0;
        
        string car_name;
        
        while (getline(ss, token, ' '))
        {
            vector<int> vec;
            stringstream sss(token);
            string temp;
            
            switch(cnt++)
            {
                case 0:
                    while (getline(sss, temp, ':'))
                    {
                        vec.push_back(stoi(temp));
                    }
                    
                    num = 60 * vec[0] + vec[1];
                    break;
                case 1:
                    car_name = token;
                    car_names.insert(car_name);
                    break;
                case 2:
                    if (token == "IN")
                    {
                        car_in_out[car_name] += num; 
                    }
                    else
                    {
                        val[car_name] += num - car_in_out[car_name]; // 마지막에 엣지 케이스를 못 찾았는데, += 대신에 =라서 문제가 생겼었음.
                        car_in_out[car_name] = 0;
                    }
                    break;
            }
        }
    }
    
    for (const string &car_ : car_names)
    {
        if (car_in_out[car_] || !val[car_])
        {
            val[car_] += 23 * 60 + 59 - car_in_out[car_];
        }
    }
}

vector<int> CalculateFees(vector<int> &f, unordered_map<string, int> &v)
{
    vector<int> ans;
    
    int normal_t = f[0];
    int normal_v = f[1];
    int unit_t = f[2];
    int unit_v = f[3];
    
    for (const string &car_ : car_names)
    {
        if (val[car_] && val[car_] <= normal_t)
        {
            val[car_] = normal_v;
        }
        else if ((val[car_] - normal_t) % unit_t)
        {
            val[car_] = normal_v + ((val[car_]- normal_t) / unit_t + 1) * unit_v;
        }
        else
        {
            val[car_] = normal_v + ((val[car_]- normal_t) / unit_t) * unit_v;
        }
        
        ans.push_back(val[car_]);
    }
    
    return ans;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    CalculateTime(records);
    answer = CalculateFees(fees, val);
    
    return answer;
}