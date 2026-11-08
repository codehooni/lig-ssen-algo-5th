#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    
    int part = participant.size();
    int winner = completion.size();
    
    unordered_map<string, int>win;
    
    
        
    for(int i=0; i<part; ++i){
        win[participant[i]] += 1;
    }
    for(int i=0; i<winner; ++i){
        win[completion[i]] -= 1;
    }
    for(int i=0 ; i<part; ++i){
        if(win[participant[i]]>0) answer = participant[i];
    }
    
   return answer;
}