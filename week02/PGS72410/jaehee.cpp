#include <string>
#include <vector>
#include<iostream>

using namespace std;
/*
선택 근거: 기존엔 solution함수 내에서 전부 만들려 했으나. 알아보기 너무 힘들고, 
          다른분들도 함수를 만들어서 하는게 어떻겠냐 하시길래 함수로 만들어보았다.
          함수로 만드니까 조금 더 알아보기 수월하였다.

핵심 로직: 각 조건별 함수를 만들어 요구를 충족하였다.
           string의 push_back() 과 size()함수를 이용하였으며, tmp에 문자열을 복사하여
           담은 후, 함수들에 파라미터로 보내 작업을 진행하고, temp2에 push_back()
           한 후, return하여 tmp에 덮어씌우며 각 단계별로 작동하도록 하였다.
           방식으로 하였다.
시간 복잡도:for문과 if문만 들어가 O(n)일 것이다.
AI사용 : AI에게 string 문법에 대한 설명을 들었다.
        string의 push_back()으로 파이썬의 .append()와 같이 수행할 수 있음을 알았고,
        pop_back도 마찬가지로 빼는걸 알수 있었다.
        
    ,,,수업들으면서 알게됐는데 그냥 temp2.begin()/temp2.end()했으면 좀 수월했을려나요..?
*/


string lv_1(string temp1) {
    string temp2;
    if (temp1.size() == 0) return temp2;

    for (int i = 0; i < temp1.size(); ++i) {
        if (temp1[i] >= 65 && temp1[i] <= 90) {
            temp2.push_back(temp1[i] + 32);
        }
        else temp2.push_back(temp1[i]);
    }
    return temp2;
}

string lv_2(string temp1) {
    string temp2;
    if (temp1.size() == 0) return temp2;
    for (int i = 0; i < temp1.size(); ++i) {
        if (temp1[i] == '-' || temp1[i] == '_' || temp1[i] == '.' || (temp1[i] <= 122 && temp1[i] >= 97) || (temp1[i] >= '0' && temp1[i] <= '9')) {
            temp2.push_back(temp1[i]);
        }
    }
    return temp2;
}

string lv_3(string temp1) {
    string temp2;
    if (temp1.size() == 0) return temp2;
    temp2.push_back(temp1[0]);
    for (int i = 1; i < temp1.size(); ++i) {
        if (temp1[i - 1] == '.') {
            if (temp1[i] != '.') temp2.push_back(temp1[i]);
            else continue;
        }
        else temp2.push_back(temp1[i]);
    }
    return temp2;
}

string lv_4(string temp1) {
    string temp2;
    if (temp1.size() == 0) return temp2;
    int len = temp1.size();
    for (int i = 0; i < len; ++i) {
        if ((i == 0&&temp1[0] == '.') || (i== len-1&&temp1[len - 1] == '.')) continue;
        else temp2.push_back(temp1[i]);
    }
    return temp2;
}

string lv_5(string temp1) {
    string temp2;
    if (temp1.size() == 0) {
        temp2.push_back('a');
    }
    else temp2 = temp1;
    return temp2;
}

string lv_6(string temp1) {
    string temp2;
    if (temp1.size() >= 16) {
        for (int i = 0; i < 15; ++i) {
            if (i == 14 && temp1[14] == '.') continue;
            temp2.push_back(temp1[i]);
        }
        
    }
    else temp2 = temp1;
    return temp2;
}
string lv_7(string temp1) {
    string temp2;
    int len = temp1.size();
    char cpy;
    if (len <= 2) {
        cpy = temp1[len - 1];
        for (int i = 0; i < len; ++i) {
            temp2.push_back(temp1[i]);
        }
        for (int i = len; i < 3; ++i) {
            temp2.push_back(cpy);
        }
    }
    else temp2 = temp1;
    return temp2;
}

string solution(string new_id) {
    string tmp = new_id;
    tmp = lv_1(tmp);
    //cout << tmp << "\n";
    tmp = lv_2(tmp);
    //cout << tmp << "\n";
    tmp = lv_3(tmp);
    //cout << tmp << "\n";
    tmp = lv_4(tmp);
    //cout << tmp << "\n";
    tmp = lv_5(tmp);
    //cout << tmp << "\n";
    tmp = lv_6(tmp);
    //cout << tmp << "\n";
    tmp = lv_7(tmp);
    //cout<<tmp<<"\n";

    return tmp;
}
