#include <vector>
#include <iostream>

using namespace std;

// 1. 핵심로직 :  추후 빠르게 작성하겠습니다.
// 2. 선택근거 :  추후 빠르게 작성하겠습니다.

vector<int> solution(vector<int> arr) 
{
    int flag = arr[0];
    vector<int> answer;
    answer.push_back(flag);
    for(int i = 1; i < arr.size(); i++)
    {
        if(flag != arr[i])
        {
            flag = arr[i];
            answer.push_back(flag);
        }
    }
    return answer;
}