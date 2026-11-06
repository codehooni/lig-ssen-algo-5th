#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


// 핵심 로직: Stack
// 선택 근거: 가장 최근 들어온 값이랑 현재 들어오는 값을 비교하는 로직이 Stack의 가장 적합하다  

// 풀이법 1: stack의 설정 
vector<int> solution(vector<int> arr) 
{
    // 초기 조건: stack을 설정하고 arr의 초깃값을 push한다 
    vector<int> answer;
    stack <int> st;
    st.push(arr[0]);
    
    // Step1: for 문을 통해 stack.top()과 arr의 현재 원솟값이 다른지 확인한다
    for (int i=1;i<arr.size();i++) {
        if (arr[i]!=st.top())
            st.push(arr[i]);
    }
    
    
    // Step2: stack의 저장한 값 순서대로 원솟값들을 vector로 옮긴다
    //  1. 
    answer.reserve(st.size());
    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }
    reverse(answer.begin(),answer.end());
    cout << "Hello Cpp" << endl;

    return answer;
}

// 풀이법 2: 풀이법 1과 동일하게 Stack을 사용하지 않고 구하기
// vector<int> solution(vector<int> arr) {
//     vector<int> answer;
//     answer.push_back(arr[0]);
//     for (int i=1;i<arr.size();i++) {
//         if (answer.back() != arr[i]) {
//             answer.push_back(arr[i]);
//         }
//     }
//     return answer;
// }