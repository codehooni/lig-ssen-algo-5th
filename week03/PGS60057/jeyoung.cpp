#include <string>
#include <vector>

using namespace std;

// 압축문자단위가 1~n일때 각각 문자를 압축 시간복잡도 n^2
int solution(string s) {
    int minanswer = 10000000;
    for (int i = 1;i <= s.size();i++) {
        string current = s.substr(0, i);
        int count = 1;
        int answer = 0;
        for (int j = i;j < s.size();j += i) {
            if (current != s.substr(j, i)) {
                answer += current.size();
                if (count > 1) answer += to_string(count).size();
                current = s.substr(j, i);
                count = 1;
            }
            else count++;
        }
        answer += current.size();
        if (count > 1) answer += to_string(count).size();
        minanswer = min(minanswer, answer);
    }
    return minanswer;
}