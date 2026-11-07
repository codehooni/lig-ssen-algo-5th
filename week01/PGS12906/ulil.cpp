#include <vector>
#include <iostream>

using namespace std;
//1. 핵심 로직: 바로 앞 칸과 같은 숫자면 건너뛰어서, 연속된 숫자 중 첫 번째만 남긴다.
//              i > 0을 먼저 확인해서 첫 칸에서 arr[-1]에 접근하지 않게 한다.
//2. 선택 근거: 중복 되는 숫자 중에서 처음 숫자만 answer에 넣으려 했다.

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        // 현재 숫자랑 그 전 숫자가 같으면 건너뜀
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        //같은 숫자의 첫번쨰만 arr 배열에 넣음
        answer.push_back(arr[i]);
    }

    return answer;
}
