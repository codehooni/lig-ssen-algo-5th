#include <string>
#include <algorithm>
using namespace std;
/*
핵심로직 : 자르는 단위를 1부터 길이의 절반까지 늘려 가며 문자열을 앞에서부터 같은 길이로 자릅니다.
이전 조각과 같으면 개수를 올리고, 다르면 (개수 + 조각)을 결과에 붙입니다. 개수가 1이면 숫자는 생략합니다.
반복이 끝난 뒤 마지막 조각도 붙이고, 모든 단위의 결과 길이 중 최솟값을 반환합니다.

사용근거 : 문자열 길이가 최대 1,000이라서 모든 단위를 시도하는 완전탐색으로 충분합니다.
단위가 길이의 절반보다 크면 같은 조각이 연속될 수 없어서 그 범위는 볼 필요가 없어요.
결과를 문자열로 직접 만들어 길이를 재면 두 자리 이상 개수도 정확히 반영됩니다.

시간복잡도 : O(N^2)

AI사용 : 로직을 모르겠어서 AI 답지 보고 학습했습니다.
*/
int solution(string s) {
    int answer = s.size();  // 길이 1일 때를 위한 기본값
    for (int size = 1; size <= (int)s.size() / 2; size++) {
        string result = "";
        string prev = s.substr(0, size);
        int count = 1;
        for (int i = size; i < (int)s.size(); i += size) {
            string cur = s.substr(i, size);  // 남는 부분은 자동으로 짧게 잘림
            if (cur == prev) {
                count++;
            } else {
                if (count > 1) result += to_string(count);
                result += prev;
                prev = cur;
                count = 1;
            }
        }
        if (count > 1) result += to_string(count);  // 마지막 조각 처리
        result += prev;
        answer = min(answer, (int)result.size());
    }
    return answer;
}