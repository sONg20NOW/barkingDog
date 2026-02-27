#include <bits/stdc++.h>
using namespace std;
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
string board[1001];
int dis[1002][1002][11];

struct XY_cnt {
    int x, y, cnt;
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        board[i] = s;
    }

    queue<XY_cnt> Q;
    dis[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()) {
        XY_cnt cur = Q.front();  Q.pop();
        // cout << "[" << cur.x << ',' << cur.y << ',' << cur.cnt << ']' << '\n';
        if (cur.x == N - 1  && cur.y == M - 1) {
            cout << dis[cur.x][cur.y][cur.cnt] << '\n';
            return 0;
        }
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.x;
            int dy = d.second + cur.y;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if (board[dx][dy] == '1') {
                // 다음 좌표가 1인 경우, cur.cnt + 1이 K보다 크지 않다면 진행
                if (cur.cnt + 1 > K || dis[dx][dy][cur.cnt + 1])    continue;
                dis[dx][dy][cur.cnt + 1] = dis[cur.x][cur.y][cur.cnt] + 1;
                Q.push({dx, dy, cur.cnt + 1});
            } else if (!dis[dx][dy][cur.cnt]) {
                dis[dx][dy][cur.cnt] = dis[cur.x][cur.y][cur.cnt] + 1;
                Q.push({dx, dy, cur.cnt});
            }
        }
    }

    cout << "-1" << '\n';
    return 0;
}