#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> map;
    for(string s:completion){
        map[s]++;
    }
    for(string s:participant){
        if(map[s]==0)
            return s;
        map[s]--;
    }
    return answer;
}