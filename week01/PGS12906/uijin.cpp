#include <vector>
#include <iostream>

using namespace std;

int last_number;

vector<int> solution(vector<int> arr) 
{
    last_number=arr[0];
    vector<int> answer={arr[0]};
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=last_number){
            last_number=arr[i];
            answer.push_back(last_number);
        }
    }

    return answer;
}