#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
bool cmp(vector<int> a, vector<int> b) {   //사실상 저번주 과제랑 똑같은 문제다 long long를 써야 한다.
    if (a[1] < b[1]) return true;
    else return false;
}
int solution(vector<vector<int>> drones, int d) {
    sort(drones.begin(), drones.end(), cmp);

    int answer = 0;
    ll Minraser = -1;

    for (int i = 0;i < drones.size();i++) {
        if (drones[i][0] > Minraser) {
            Minraser = ll(drones[i][1]) + ll(d);
            answer++;
        }
    }
    return { answer };
}
