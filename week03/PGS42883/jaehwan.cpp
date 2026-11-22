// PGS 42883
// 큰 수 만들기

#include <string>
#include <vector>
using namespace std;


// 가설 1: end 변수의 길이 만큼 반복문을 돌면서 max 값 산정 후 그 이후부터 정답이 채워질 때까지 반복
// ai에게 도움 받아서 깔끔하게 수정했으나 테스트 케이스에 약소한 차이로 실패
// -- 2시간 초과 --

string solution(string number, int k) {
    // 여기에 코드를 작성하세요.
    string answer = "";
    int start_idx = 0;
    int answer_len = number.length() - k;
    while(answer.length() < answer_len)
    {
        char max_val = -1;
        int max_idx = 0;
        //15번 줄은 ai에게 도움 받음
        int end = number.length() - (answer_len - answer.length());
        for(int j = start_idx; j < end; j++)
        {
            if(number[j] > max_val)
            {
                max_idx = j;
                max_val = number[j];
            }
        }
        answer.push_back(number[max_idx]);
        start_idx = max_idx + 1;
    }
    return answer;
}
