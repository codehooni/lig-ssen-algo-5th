#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <tuple>
#include <cstdlib>
using namespace std;

#define MAX_N 100001

/*
    시간 복잡도: O(N) - 입력 제외하고 dfs만 고려했을 때 
    접근 방식: 임의의 노드(1) 기준으로 가장 먼 노드를 찾고 해당 노드에서 가장 먼 노드까지 거리를 구함
    선택 근거:
        1. 노드 수가 최대 10만이므로 연결리스트 기반으로 그래프 생성
        2. 트리에서 가장 먼 노드를 탐색해야 하므로 깊이 우선 탐색인 dfs 선택
    핵심 로직:
        1. 임의 노드(1)에서 dfs를 수행해 가장 거리가 먼 노드를 찾음
        2. 1에서 구한 노드에서 dfs를 다시 한번 수행해 가장 먼 노드까지 거리를 구함
        (가능 이유: 트리는 사이클이 없는 그래프이므로, 특정 노드 기점으로 노드 간 경로가 유일하기 때문에)
*/

int V;
vector<pair<int, int>> tree[MAX_N];

vector<int> split(string& input) {
    vector<int> v;
    stringstream ss(input);
    int num;
    
    while (ss >> num) v.push_back(num);
    return v;
}

void input_data() {
    string temp;
    
    cin >> V;
    cin.ignore();
    
    for (int i = 0; i < V; i++) {
        getline(cin, temp);
        vector<int> pv = split(temp);
        int start = pv[0];
        auto it = pv.begin() + 1;
        
        while(*it != -1) {
            tree[start].push_back({ *it, *(it + 1)});
            it += 2;
        }
    }
}

void print_data() {
    for (int i = 1; i <= V; i++) {
        for (auto n : tree[i]) {
            cout << "(" << n.first << ", " << n.second << ") ";
        }
        cout << endl;
    }
}

// 재귀 풀이 - 스택 오버플로우 위험
pair<int, int> dfs(int from, int parent, int dist) {
    pair<int, int> maxNode = { from, dist };
    
    for (auto p: tree[from]) {
        int to = p.first;
        int val = p.second;

        if (to == parent) continue;
        auto result = dfs(to, from, dist + val);

        if (result.second > maxNode.second) {
            maxNode = result;
        }
    }

    return maxNode;
}

// stk 기반 풀이
pair<int, int> dfsStk(int start) {
    int from, parent, total, to, dist;
    vector<tuple<int, int, int>> stk;
    stk.push_back(make_tuple(start, -1, 0));
    pair<int, int> maxDist = { start, 0 };
    
    while (!stk.empty()) {
        tie(from, parent, total) = stk.back();
        stk.pop_back();

        if (total > maxDist.second) {
            maxDist = { from, total };
        }

        for (auto p : tree[from]) {
            tie(to, dist) = p;
            if (to == parent) continue;
            stk.push_back(make_tuple(to, from, total + dist));
        }
    }

    return maxDist;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input_data();
    // print_data();

    pair<int, int> start = dfsStk(1);
    pair<int, int> end = dfsStk(start.first);
    cout << end.second << endl;
    
    return 0;
}