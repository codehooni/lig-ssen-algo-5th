// PGS 72410
// 신규 아이디 추천

#include <string>
#include <vector>

using namespace std;

// 1. 핵심 로직: 문자열 처리 함수들을 통한 문자열 조작
// 2. 선정 이유: 직관적이고 정확한 문제풀이를 위해서

string solution(string new_id) {
    string answer = new_id;
    for(int i = 1; i <= 7; i++)
    {
        auto iter = answer.begin();
        switch(i)
        {
        case 1:
        // 1단계: new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
            for(int k = 0; k < answer.size(); k++)
            {
                if(answer[k] >= 'A' && answer[k] <= 'Z') answer[k] += ('a' - 'A');
            }
            break;
        case 2:
        // 2단계: new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
            while(iter != answer.end())
            {
                if(((*iter >= 'a' && *iter <= 'z') 
                    || (*iter >= '0' && *iter <= '9')
                    || (*iter == '-') || (*iter == '_') || (*iter == '.')))
                        { iter++; }
                else answer.erase(iter);
            }
            break;
        case 3:
        // 3단계: new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
            {
                int n;
                while((n = answer.find("..")) >= 0) answer.replace(n, 2, ".");
                break;
            }
        case 4:
        // 4단계: new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
            if(answer[0] == '.') answer.erase(answer.begin());
            if(*(answer.end() - 1) == '.') answer.erase(answer.end() - 1);
            break;
        case 5:
        // 5단계: new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
            if(answer == "") answer.push_back('a');
            break;
        case 6:
        // 6단계: new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
        //만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
            if(answer.size() >= 16) answer = answer.substr(0, 15);
            if(answer.back() == '.') answer.erase(answer.end() - 1);
            break;
        case 7:
        // 7단계: new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
            if(answer.size() <= 2) 
            {
                char ch = answer.back();
                while(answer.size() < 3)
                {
                    answer.push_back(ch);
                }
            }
            break;
        default:
            break;
        }
    }
    return answer;
}