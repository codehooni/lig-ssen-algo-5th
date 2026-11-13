#include <string>
#include <vector>
#define MIN_LEN 3
#define MAX_LEN 15

using namespace std;

/*
* 1. 핵심 로직: 복잡한 로직은 사용하지 않았고,
*              string 클래스에 있는 메소드를 이용해 충실히 구현함.
*
* 2. 선택 근거: 7단계까지 있고, 문자열의 길이가 최대 1,000으로
*              O(N^2)까지 가능할만큼 시간복잡도에 여유가 있는 것으로 보아
*              주어진 단계를 충실히 구현하는 문제로 판단함.
*/

/*
1. 아이디 생성 업무
2. 규칙 x -> 규칙 o 유사 아이디 추천
3. 규칙
    1) 3 ~ 15
    2) 알파벳 소문자,-,_,.만 가능
    3) .은 처음과 끝에 오면 안 됨
    4) .은 연속 사용하면 안 됨
4. 어떻게 바꿀까?
    1) 대문자 -> 소문자
    2) 특정 기호 제외한 모든 문자 제거
    3) . 두 번 이상을 하나로 치환
    4) 처음과 끝의 . 제거
    5) 빈 문자열이면 new_id에 a 대입
    6) 16자 이상이면 첫 15개만 남기기
    7) new_id가 2자 이하 -> 마지막 문자를 길이가 3이 될 때까지 붙이기
*/

void Step1(string &id_in)
{
    for (int i = 0; i < id_in.size(); i++)
    {
        if (id_in[i] >= 'A' && id_in[i] <= 'Z')
        {
            id_in[i] += ('a' - 'A');
        }
    }
}

void Step2(string &id_in) // 인덱스가 앞으로 하나씩 당겨짐 주의
{
    for (int i = 0; i < id_in.length();)
    {
        if ((id_in[i] <= 'z' && id_in[i] >= 'a') ||
            (id_in[i] <= '9' && id_in[i] >= '0') ||
            (id_in[i] == '-' || id_in[i] == '_' || id_in[i] == '.'))
        {
            i++;
            continue;
        }
        
        id_in.erase(i, 1);
    }
}

void Step3(string &id_in)
{
    char prev = ' ';
    
    for (int i = 0; i < id_in.length();)
    {
        if (id_in[i] == '.')
        {
            if (prev == '.')
            {
                 id_in.erase(i, 1);
            }
            else
            {
                prev = '.';
                i++;
            }
                
            continue;
        }
        
        prev = ' ';
        i++;
    }
}

void Step4(string &id_in)
{
    if (!id_in.length()) return;
    if (id_in[0] == '.') id_in.erase(0, 1);
    if (id_in[id_in.length() - 1] == '.') id_in.erase(id_in.length() - 1, 1);
}

void Step5(string &id_in)
{
    if (id_in.length()) return;
    id_in = "a";
}

void Step6(string &id_in)
{
    if (id_in.length() > MAX_LEN)
        id_in.erase(MAX_LEN, id_in.length() - MAX_LEN);
}

void Step7(string &id_in)
{
    if (id_in.length() < MIN_LEN)
        id_in.append(MIN_LEN - id_in.length(), id_in[id_in.length() - 1]);
}

string solution(string new_id)
{
    string answer = "";
    
    Step1(new_id);
    Step2(new_id);
    Step3(new_id);
    Step4(new_id);
    Step5(new_id);
    Step6(new_id);
    Step7(new_id);
    Step4(new_id); // 15자로 줄이다보면 맨 마지막 문자가 .이 될 수가 있다.
    
    answer = new_id;
    
    return answer;
}