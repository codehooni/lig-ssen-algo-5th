#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev = -1;

    for (int i : arr) {
        if (prev != i) answer.push_back(i);
        prev = i;
    }

    return answer;
}