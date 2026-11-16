#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool visited[100001];
int Max;
//미해결
//gpt 도움받음
// 1번정점에서 dfs해서 가장 먼 정점 A찾고 A에서 dfs 돌려서 가장 먼 정점 찾으면 됨
// dfs 2번이므로 시간복잡도는 O(V)
int dfs(int s, const vector<vector<pair<int, int>>>& v, int cost) {
    vector<pair<int, int>> st;
    st.push_back({ s, cost });
    visited[s] = true;

    Max = cost;
    int farthest = s;

    while (!st.empty()) {
        int cur = st.back().first;
        int curCost = st.back().second;
        st.pop_back();

        if (curCost > Max) {
            Max = curCost;
            farthest = cur;
        }

        for (int i = 0; i < v[cur].size(); ++i) {
            int nxt = v[cur][i].first;
            if (!visited[nxt]) {
                visited[nxt] = true;
                st.push_back({ nxt, curCost + v[cur][i].second });
            }
        }
    }

    return farthest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;
    vector<vector<pair<int, int>>> v(V + 1);

    for (int i = 0; i < V; ++i) {
        int a;
        cin >> a;

        while (true) {
            int b;
            cin >> b;
            if (b == -1) break;

            int c;
            cin >> c;
            v[a].push_back({ b, c });
        }
    }

    int farthest = dfs(1, v, 0);
    fill(visited, visited + V + 1, false);

    dfs(farthest, v, 0);
    cout << Max << '\n';
}