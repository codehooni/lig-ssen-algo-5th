#include <string>
#include <vector>
#include<iostream>
#include<sstream>
#include<map>
using namespace std;
/*
핵심로직 : sstream을 이용하여 문자열 분해, 및 vector의 push_back위주로 문자열을 분해 및 각 벡터에 넣고, 
구조체와 map을 통해 dict처럼 key-value로 저장, 및 정렬 하여 주차 시간 계산을 하였습니다.

선택근거 : 문자열 분해는 찾아본 결과 sstream을 한 후, while(rec >> temp1)이처럼 임시변수에 나눈 문자열을 담고,
이를 벡터안에 집어넣는 방식이 제가 이해하고, 사용하기 가장 쉬워보여 사용하였으며,
map의 경우 c++수업시간에 map이 나왔는데, key-value로 값을 저장한다길래 사용하면 좋을거 같아 사용하였습니다.
또한 map을 사용하려는데 담아야될 값이 너무 많은거 같아 ai에게 물어보니 구조체도 map에 value로 넣을 수 있다길래
해보았습니다.

시간복잡도:O(RlogN)

AI설명참고:sstream 및 map에 대한 설명, 특히 map을 어떤식으로 사용하고 구조체 및 벡터들로도 map을 할 수 있다는
사실을 배웠으며, 그 외에도 오류를 너무 못찾겠어서 AI도움을 빌려(코드는 적지말아달라 했습니다.) 오류를 수정하였습니다.
sstream으로 나눈건 while(rec>>temp1){num.push_back(temp1))이렇게 바로 임시변수에 넣으면서 벡터로 집어넣는 방법이있고,
getline(rec,a,':')처럼 getline을 통해 해당 기호 앞, 뒤로도 나눌 수있다는 것을 알았습니다.
또한 map의 key-value로는 일반적인 int, char, string형태 뿐 아닌 vector-vector 끼리도 가능하며, value로 벡터나
구조체도 넣을 수 있다는 것을 배웠습니다.

*/


typedef struct record {
    vector<int> in;
    vector<int> out;
    bool now=1;
    int fee = 0;
}r_list;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<string>times;
    vector<int>time_m;
    vector<int>num;
    vector<string>iout;
    string tmp1, tmp3;
    vector<bool>inout;
    vector<int>answer;
    int tmp2;
    
    for (int i = 0; i < records.size(); i++) {
        stringstream rec(records[i]);

        while (rec >> tmp1>>tmp2>>tmp3) {
            times.push_back(tmp1);  //시간 넣어주기
            num.push_back(tmp2);   //차번호넣어주기
            iout.push_back(tmp3);  //iout 넣어주기
        }
    }
//이제 해야될거: 시간분해하기, 차번호 map지정하기, iout bool로 1 0 으로 전환하기
    for (int i = 0; i < iout.size(); ++i) {
        if (iout[i] == "IN") inout.push_back(1);
        else inout.push_back(0);
    }//iout bool로 바꾸기
    
     
     //시간바꾸기 >>전부 분으로
    for (int i = 0; i < times.size(); ++i) {
        stringstream tm(times[i]);
        string a, b;
        getline(tm, a, ':');
        getline(tm, b, ':');
        int t = stoi(a) * 60 + stoi(b);
        time_m.push_back(t);
    } //time_m은 시간>분으로 바꾼 벡터

    //차 번호 map하기
    map <int, r_list> fin_list;
    for (int i = 0; i < num.size(); ++i) {
        if (inout[i] == 1) {   //입차
            fin_list[num[i]].in.push_back(time_m[i]);
            fin_list[num[i]].now = 1;
        }
        if(inout[i] ==0) {    //출차기록
            fin_list[num[i]].out.push_back(time_m[i]);
            fin_list[num[i]].now = 0;
        }
        
    }
    //fee[0] = 기본시간, fee[1] = 기본요금 fee[2]=단위시간, fee[3] = 단위요금
    //이러면 차번호 - 구조체 형식으로 매핑, (입차시간, 출차시간 및 현재상태 기록,)
    for (auto& [n,info] : fin_list) {
        
        if (info.now != 0) { //출차가 없는경우 >>why? 출차하고 출차할 일은 없기때문에
            info.out.push_back(1439); //23:59분 분변환 한 수
        }

        int out_p = info.out.size();  //출차한 횟수만큼
        int p_time = 0; //주차시간
        int tot=0; // 추가 요금시간
        for (int i = 0; i < out_p; ++i) {
            p_time+=(info.out[i] - info.in[i]);
        }

        if (p_time <= fees[0]) tot=0;
        else {
            int check = p_time - fees[0]; // check에 기본시간 뺀 시간 넣기
            tot = check / fees[2];
            if (check % fees[2] != 0) tot += 1;
        }
        info.fee = fees[1] + tot * fees[3];
        answer.push_back(info.fee);
    }
    return answer;
}

