#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
1. 핵심 로직: 문자열을 for문을 돌면서 단위로 자른다. 자르고 이전 값과 비교한다. 같으면 문자열에 더하지 말고 우선 다음으로 진행한다.
             이후 이전 값과 현재값이 달라지는 시점이 생기면 cnt + 1을 해서 앞에 붙이고, 자른 문자열을 붙인다.
             로직이 끝난 이후엔 남아있는 cnt와 prev, curr을 이용해서 더해지지 못 했던 자른 문자열을 더해준다. (이 부분을 간과했었다.)

2. 선택 근거: 문자열 문제이고 특정 단위로 자르는 문제이므로 특정 길이로 자르는 함수인 substr을 이용해서 잘라 비교하는 것이 합리적이라고 생각했다.
             문자열의 길이가 길지 않으므로 단순 반복문이어도충분히 가능할 것으로 판단했다.
*/

/*
1. 어피치는 문자열을 압축하는 방법에 대해 공부
2. 비손실 압축
3. 한 번만 나타나면 1은 생략함
4. 1개 이상의 단위로 잘라서 압축하기 -> 그중 가장 작은 걸로 압축하기
5. 아마 중간에 중단할 필요가 있을지도..? 최소값보다 단위가 1작으면 중단해도 됨.
6. 소문자로만

Claude가 찾아준 버그
1.  prev != curr에만 prev를 temp에 쓰고 있는데, 그래서 루프가 끝날 때 아직 쓰지 않은 prev, cnt가 사라짐.
    else 분기에서 break할 때도 마찬가지
    -> 남아있는 prev와 cnt를 한 번 더 처리하는 부분이 필요
2. s.length() - j > i는 남은 길이가 정확히 i일 때도 else로 빠짐.
   마지막 조각이 prev와 같아도 비교없이 그냥 붙고 끝남
   -> substr(j, i)는 남은 길이가 i보다 짦으면 알아서 남은 만큼만 잘라줌. 짧은 꼬리는 prev와 절대로 같을 수 없음
   -> 특별 취급할 필요가 없음.
3. num 계산이 틀림 -> 반복횟수를 항상 1의 자리로 가정하고 있는데, 10이나 100처럼 2 ~ 3자리가 될 수 있음.
*/

int solution(string s) {
    // 최솟값
    int min_value = s.length();
    
    for (int i = 1; i <= s.length() / 2; i++)
    {
        string prev;
        string temp;
        string curr;
        
        int num = 0;
        int cnt = 0;
        
        for (int j = 0; j < s.length(); j += i)
        {
            if (!j)
            {
                prev = s.substr(0, i);
                continue;
            }
            
            curr = s.substr(j, i);
            
            if (prev == curr)
            {
                cnt++;
            }
            else
            {
                if (cnt)
                {
                    temp += to_string(cnt + 1) + prev;
                    cnt = 0;
                }
                else
                {
                    temp += prev;
                }
                prev = curr;
            }
        }
        
        if (cnt)
        {
            if (prev == curr)
            {
                temp += to_string(cnt + 1) + prev;
            }
            else
            {
                temp += to_string(cnt + 1) + prev + curr;
            }
        }
        else
        {
            temp += curr;
        }
        
        // cout << "temp: " << temp << endl;
        min_value = min(min_value, (int)temp.length());
        // cout << "min_value: " << min_value << endl;
    }

    return min_value;
}