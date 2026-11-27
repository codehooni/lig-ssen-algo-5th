#include <string>
#include <vector>
#include <cctype>
using namespace std;

// 접근 방식 : 각 괄호에 대응하는 숫자 문자열과 내용 문자열을 구조체 배열을 이용한 스택 구현 형식으로 저장.
//          스택 방식으로 진행하며 구조체 배열을 갱신한다. 
// 풀이 로직 : 
// {string num,string text}를 구성 요소로 갖는 배열 array 작성. 괄호 깊이 변수 int depth, 숫자열 입력 변수 bool num_input 작성.
// (숫자 문자열, 내용 문자열)을 매개변수로 하고, 그 횟수만큼 반복된 문자열을 반환하는 문자열 함수 multiple() 작성.
// 1.알파벳 입력 시 : 현재 깊이의 text에 추가.
// 2.숫자 입력 시 :
// num_input=false면 depth를 1추가하고 arr[depth].num에 숫자 추가. num_input을 true로 변경.
// num_input=true면 arr[depth].num에 숫자 추가.
// 3.여는 괄호 입력 시 : num_input을 false로 변경.
// 4.닫는 괄호 입력 시 : 현재 depth의 숫자와 내용을 multiple() 처리한 문자열을 arr[depth-1].text에 추가.
//                      arr[depth]를 ["",""]로 초기화.(새로운 문자열 처리 준비.) depth를 1감소.
// 시간 복잡도 : O(N + K). N:입력 문자열의 길이, K:복원 과정에서 생성되는 문자열의 총 길이.

struct text_pair{
    string num = "";
    string text = "";
};

text_pair arr[30000];
int depth;
bool num_input;

string multiple(const text_pair& t){
    string answer="";
    int n=stoi(t.num);
    for (int i = 0; i < n; i++){
        answer+=t.text;
    }
    return answer;
}

string solution(string code) {
    depth=0;
    num_input=false;

    arr[0].num="";
    arr[0].text="";

    for (char c : code) {
        if (isalpha(c)){
            arr[depth].text+=c;
        }
        else if (isdigit(c)){
            if (num_input){
                arr[depth].num+=c;
            }
            else{
                depth+=1;
                arr[depth].num+=c;
                num_input=true;
            }
        }
        else if (c=='[') {
            num_input=false;
        }
        else if (c==']') {
            arr[depth-1].text+=multiple(arr[depth]);
            arr[depth].num="";
            arr[depth].text="";
            depth-=1;
        }
    }
    
    return arr[0].text;
}