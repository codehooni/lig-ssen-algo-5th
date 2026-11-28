#include <string>
#include <vector>
using namespace std;

string solution(string code) {  //스택 활용, reverse 함수에 대해 알게되었음, stoi(string to int) 함수에 대해 알게되었음
                                //지금까지 사용한 c++ 문자열 함수 정리 to_string(숫자를 string으로), stoi(string to int), reverse
    string st = "";
    string answer = "";
    for (int j = 0;j < code.size();j++) {
        if (code[j] == ']') {
            string rs = "";
            while (st.back() != '[') {
                rs += st.back(); st.pop_back();
            }
            st.pop_back();
            reverse(rs.begin(), rs.end());

            string is = "";
            while (!st.empty() && st.back() - '0' >= 0 && st.back() - '0' <= 9) {
                is += st.back(); st.pop_back();
            }
            reverse(is.begin(), is.end());

            for (int i = 0;i < stoi(is);i++) {
                st += rs;
            }

        }
        else {
            st += code[j];
        }
    }
    return { st };
}