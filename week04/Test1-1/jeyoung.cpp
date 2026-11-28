#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[101][101][11];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct Point {
    int x = 0;
    int y = 0;
    int kcount = 0;
    int cnt = 0;
};

int solution(vector<string> field, int k) {
    for (int i = 0;i < field.size();i++) {
        for (int j = 0;j < field[0].size();j++) {
            for (int n = 0;n <= k;n++) {
                visited[i][j][n] = false;
            }
        }
    }
    queue<Point> q;

    for (int i = 0;i < field.size();i++) {      //bfs로 풀이, 해당 문제는 일반 최단거리문제와 다르게 이차원 방문배열이 아니라 3차원 방문배열을 사용해야한다.
        for (int j = 0;j < field[0].size();j++) { //다음에 방문할 점들을 고를때, 단순히 이전에 방문한적이 있냐 없냐를 고려하는 것이 아니라 레이저를 몇번 맞고 방문한 적이 있냐를 고려해야한다.
                                                  //따라서 기존에 이차원배열에서 레이저를 몇번 맞고 그 점을 방문했는지 고려하여 삼차원배열 방문 배열을 써야한다.
            if (field[i][j] == 'S') {
                Point start = { i,j,0,0 };
                visited[i][j][0] = true;
                q.push(start);
                while (!q.empty()) {
                    Point front = q.front(); q.pop();
                    if (field[front.x][front.y] == 'E') {
                        return front.cnt;
                    }
                    for (int a = 0;a < 4;a++) {
                        int dnx = front.x + dx[a];
                        int dny = front.y + dy[a];

                        if (dnx >= 0 && dny >= 0 && dnx < field.size() && dny < field[0].size()) {
                            if ((field[dnx][dny] == '.' || field[dnx][dny] == 'E') && !visited[dnx][dny][front.kcount]) {
                                visited[dnx][dny][front.kcount] = true;
                                q.push({ dnx,dny,front.kcount,front.cnt + 1 });
                            }

                            if (field[dnx][dny] == 'R' && front.kcount < k && !visited[dnx][dny][front.kcount + 1]) {
                                visited[dnx][dny][front.kcount + 1] = true;
                                q.push({ dnx,dny,front.kcount + 1,front.cnt + 1 });
                            }
                        }
                    }
                }
            }
        }
    }
    return { -1 };
}
