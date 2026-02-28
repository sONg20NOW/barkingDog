#include <bits/stdc++.h>
using namespace std;
string board[1001];
struct XY_wall {
    int x, y, wall_cnt;
};
int vis[1001][1001][11];
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        board[i] = s;
    }

    queue<XY_wall> Q;
    Q.push({0, 0, 0});
    vis[0][0][0] = 1;

    bool day = true;
    while (!Q.empty()) {
        int size = Q.size();
        while (size--) {
            XY_wall cur = Q.front();    Q.pop();
            if (cur.x == N - 1 && cur.y == M - 1) {
                cout << vis[cur.x][cur.y][cur.wall_cnt] << '\n';
                return 0;
            }
            bool wait = false;
            for (pair<int,int> d : dir) {
                int dx = d.first + cur.x;
                int dy = d.second + cur.y;
                if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
                if (board[dx][dy] == '0') {
                    if (vis[dx][dy][cur.wall_cnt] != 0)  continue;
                    Q.push({dx, dy, cur.wall_cnt});
                    vis[dx][dy][cur.wall_cnt] = vis[cur.x][cur.y][cur.wall_cnt] + 1;
                }
                else {
                    // 벽 부수기 횟수가 없으면 패스
                    if (cur.wall_cnt + 1 > K || vis[dx][dy][cur.wall_cnt + 1] != 0)   continue;
                    // 만약 밤이라면 대기해야 하므로 Q에 다시 넣기
                    if (!day) {
                        wait = true;
                    } 
                    // 낮이라면 벽 부수기 (벽 부수는 횟수가 남는 경우만)
                    else {
                        Q.push({dx, dy, cur.wall_cnt + 1});
                        vis[dx][dy][cur.wall_cnt + 1] = vis[cur.x][cur.y][cur.wall_cnt] + 1;
                    }
                } 
            }
            if (wait) {
                Q.push({cur.x, cur.y, cur.wall_cnt});
                vis[cur.x][cur.y][cur.wall_cnt]++;
            }
        }

        day = !day;
    }

    cout << -1 << '\n';
    return 0;
}