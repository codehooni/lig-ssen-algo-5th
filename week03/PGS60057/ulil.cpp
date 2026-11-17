#include <string>
#include <vector>
#include <algorithm>   

using namespace std;
//1. 핵심 로직: 자르는 길이 len을 1부터 문자열 길이의 절반까지 하나씩 다 해 본다.
//              앞에서부터 len 글자씩 잘라서, 바로 앞 조각(prev)과 지금 조각(curr)이 같으면 개수만 늘린다.
//              다르면 지금까지 묶은 조각을 결과에 붙이고(2개 이상이면 개수도 앞에 붙임) 새 조각으로 다시 시작한다.
//              for문이 끝나면 마지막 조각은 아직 안 붙었으므로 한 번 더 붙이고, 결과 길이가 가장 짧은 값을 정답으로 한다.
//2. 선택 근거: 어떤 길이로 잘라야 가장 짧은지 미리 알 수 없지만, 문자열이 최대 1,000자라 전부 해 봐도 충분히 빠르다.
//              압축되려면 같은 조각이 최소 2개 연달아 나와야 해서, 절반보다 길게 자르는 경우는 볼 필요가 없다.
//              압축이 하나도 안 되면 원래 길이가 정답이므로, answer를 s.size()로 시작했다.
// (AI 활용 참고) (int)s.size(): size()는 음수가 없는 정수(size_t)를 돌려줘서 int로 바꿔 맞췄다.
//               타입이 다른 비교 경고를 막고, 빈 문자열에서 size() - 1 같은 뺄셈을 할 때
//               -1이 아니라 엄청 큰 수가 되는 실수를 막기 위해서다.
int solution(string s) {
    int answer = s.size(); // 압축 안 했을 때 길이로 시작

    for(int len = 1; len <= (int)s.size() / 2; len++){ //길이는 문자열 절반만큼만 비교
        string result = "";
        string prev = s.substr(0, len);
        int cnt = 1;
        
        for (int i = len; i < (int)s.size(); i += len){ 
            string curr = s.substr(i, len);
            if( prev == curr)
                cnt++;
            else{
                if(cnt > 1) result += to_string(cnt);
                result += prev;
                prev = curr;
                cnt = 1;
            }
        }
        if(cnt > 1) result += to_string(cnt); // 마지막 문자 처리
        result += prev;
        
        if ((int)result.size() < answer) answer = result.size();
    }

    return answer;
}
