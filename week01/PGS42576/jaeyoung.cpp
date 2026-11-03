#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> s;

    for (int i = 0;i < participant.size();i++) {
        if (s.find(participant[i]) == s.end()) {
            s[participant[i]] = 0;
        }
        else {
            s[participant[i]] += 1;
        }
    }
    for (int i = 0;i < completion.size();i++) {
        s[completion[i]] -= 1;
    }
    for (int i = 0;i < participant.size();i++) {
        if (s[participant[i]] == 0) {
            return participant[i];
        }
    }

}