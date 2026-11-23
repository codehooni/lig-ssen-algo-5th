#include <string>
#include <vector>
using namespace std;
/*
1.핵심로직 : 벡터를 push_back 이랑 pop_back를 이용해서 스택처럼 활용하여 풀었습니다.
            첫 요소를 새 벡터에 집어넣고, 새 요소를 해당 요소랑 비교해서 새 요소가 클 경우 제거 후 대체하고 카운트를 +1,
            작을경우 그냥 넣었습니다.
            이후 해당 카운트가 0(앞에서 뺄 필요가 없엇을 경우)엔 맨 뒤에서 제거하였습니다.
2.사용근거 : 큰 수를 만들기위해선 앞에서 큰 숫자만 이용할 필요가 있었고, 유동적으로 사용하기 위해서 vector을 사용했는데,
            막상 짜고나서 보니 스택이랑 다를바가 없엇습니다.
3.시간복잡도 : O(N^2)
4.AI사용 : 로직 검증차 사용하였습니다. 암만 생각해봐도 큰수를 만드는 방법이 안떠올라서 고민하다가
          클로드한테 내가 생각한게 맞아? 하면서 물어보니까 대답은 잘해주더라구요
          그리고 vector->string으로 바꾸는 방법도 물어보았습니다.
          그냥 string 변수안에 집어넣으면 되는 줄 알았는데 시작,끝지점 설정을 해줘야 된다는 것을 알았습니다.

          안에 for문이랑 조건문이 좀 번거롭게 작성되어서 while문안에 조건을 다 집어넣어서 한것도 주석으로 넣긴했습니다.
          다른 방식으로 풀거나 개선할 점 있으면 말씀해주시면 감사하겠습니다.

*/
string solution(string number, int k) {
    int n=number.size();
    int stk = 0;
    vector<char>temp_num;
    temp_num.push_back(number[0]);
            /*
    for(int i=1; i<n; ++i){
        for(auto x:temp_num){
            if(stk<k){
                if(temp_num.empty()) continue;
                if(number[i]>temp_num.back()){
                    temp_num.pop_back();
                    stk+=1;  
                }
            }
        }
        */
            
            for(int i=1; i<n; ++i){
                    while(!temp_num.empty()&&stk<k&&number[i]>temp_num.back()){
    
                                temp_num.pop_back();
                                stk+=1;  
                        }
        }
        
        
            temp_num.push_back(number[i]);
        
    }
    if(stk==0){
            for(int i=0; i<k; ++i){
                temp_num.pop_back();
            }
        }
    
    string answer(temp_num.begin(), temp_num.end());
    return answer;
}
