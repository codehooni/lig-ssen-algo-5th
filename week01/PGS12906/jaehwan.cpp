#include <vector>
#include <iostream>

using namespace std;
                  
// 1. 핵심로직 :    flag 변수를 이용해 배열의 요소의 값과 같은지 확인하는 완전 탐색을 진행
// 2. 선택근거 :    arr에 있는 값을 전부 봐야하기 때문에 완전 탐색으로 진행했습니다.

vector<int> solution(vector<int> arr) 
{
    int flag = arr[0];
    vector<int> answer;
    //배열의 첫 번째 요소를 flag에 넣고 그 다음 요소부터 flag와 일치 하는지 확인
    answer.push_back(flag);
    for(int i = 1; i < arr.size(); i++)
    {
        if(flag != arr[i])
        {
            //flag와 다르면 flag를 변경하고 벡터에 push
            flag = arr[i];
            answer.push_back(flag);
        }
    }
    return answer;
}