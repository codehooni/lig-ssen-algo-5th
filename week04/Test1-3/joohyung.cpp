#include <string>
#include <vector>
#include <stack>
#include <cctype>
// 풀이 알고리즘: Stack
// 시간 복잡도: O(N)
// 풀이 로직: 
//   1) 문제 정의상 배열을 여는 기호 '[' 앞에 무조건 나타날 정수와 나타날 수도 있는 문자열을 stack에 같은 level에 쌓는다  EX) "x10[y]z"에서 문자열 x와 정수 10은 동시에 Stack에 쌓인다
//   2) 배열을 닫는 기호 ']'가 나타나면  []안에 있는 문자열과 정수 stack에 top에 있는 값을 곱하여 괄호 안에 있는 문자열을 없데이트 한다
//   3) 괄호를 완전히 빠져나온 경우 정답에 더한다
using namespace std;
string RepeatString(string str, int n){ // Python에서 가능한 string에 곱샘 작업을 적용하는 함수
    if (str.empty()){
        return str;
    }

    string answer="";
    for(int i=0;i<n;i++)
        answer+=str;

    return answer;
}
string solution(string code) {
    // 여기에 코드를 작성하세요.
    stack<int> st_int;
    stack<string> st_string;

    string cur;
    int num=0;

    string answer="";
    for (int i=0;i<code.size();i++) {
        if (code[i]=='['){ // Case 1: '['가 나타나는 경우
            st_int.push(num);
            st_string.push(cur);

            num=0;
            cur="";
        }
        else if (code[i]==']') // Case 2: 문자로 ']'가 나타나는 경우
        {
            string tmp = RepeatString(cur,st_int.top());
            st_int.pop();
            
            cur=st_string.top()+tmp;
            st_string.pop();

            if (st_int.empty())
            {
                answer+=cur;
                cur="";
            }

        }
        else if (isdigit(code[i])) // Case 3: 숫자가 나타나는 경우
        { 
            num=num*10+code[i]-'0';
        }
        else { // Case 4: 문자가 나타나는 경우
            cur+=code[i];
        }
    }
    answer+=cur;
    return answer;
}
