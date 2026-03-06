#include <bits/stdc++.h>
using namespace std;
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
string board[1000];
int dist[2][1000][1000];

struct XY_wall {
    int x, y, wall;
};

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        board[i] = s;
    }

    queue<XY_wall> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while(!Q.empty()) {
        XY_wall cur = Q.front();    Q.pop();
        if (cur.x == N - 1 && cur.y == M - 1) {
            cout << dist[cur.wall][cur.x][cur.y] << '\n';
            return 0;
        }
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.x;
            int dy = d.second + cur.y;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if (board[dx][dy] == '1') {
                if (cur.wall || dist[1][dx][dy])    continue;
                dist[1][dx][dy] = dist[0][cur.x][cur.y] + 1;
                Q.push({dx, dy, 1});
            } else {
                if (dist[cur.wall][dx][dy]) continue;
                dist[cur.wall][dx][dy] = dist[cur.wall][cur.x][cur.y] + 1;
                Q.push({dx, dy, cur.wall});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}