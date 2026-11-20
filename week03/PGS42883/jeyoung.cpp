#include <string>
#include <vector>

using namespace std;
//의진님의 도움을 받아 풀이했습니다
string solution(string number, int k) {
    string answer = "";
    //스택의 탑보다 현재값이 크다면 pop -> 지역해
    //지역해를 반복하면 전역해가 된다
    //최대한 큰수가 큰자리에 오게 하기위한 그리디 알고리즘
    for (int i = 0;i < number.size();i++) {
        if (answer.size() == 0 || answer.back() >= number[i]) {
            answer += number[i];
        }
        else {
            while (k > 0 && answer.size() > 0 && answer.back() < number[i]) {
                answer.pop_back();
                k--;
            }
            answer += number[i];
        }
    }

    while (k > 0) {   //모든과정을 끝내고 k가 남아있다면 k자리개만큼 뒷자리 없애기
        answer.pop_back();
        k--;
    }
    return answer;
}