#include <vector>
#include <iostream>

using namespace std;
/*
핵심 로직: 벡터 사용하기
알고리즘 : 반복문 및 조건문,
선택이유  : push_back과 size()함수의 사용을 위해 사용
push_back으로 인해 바로 vector에 숫자를 넣으면서 비교하기쉽게함

*/


vector<int> solution(vector<int> arr) 
{
    vector<int>answer;
    int n = arr.size();
    int t;
    for(int i=0; i<n; i++){
        
        if(i!=0){ 
            if(arr[i]!=arr[i-1]){ 
                answer.push_back(arr[i]);
           }
        }
        else answer.push_back(arr[0]);
                             
    }
    

    return answer;
}