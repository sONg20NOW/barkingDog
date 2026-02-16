#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int vis[102][102];

pair<int,int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
            vis[i][j] = -1;
        }
    }

    queue<pair<int, int>> Q;
    vis[0][0] = 0;
    Q.push({0, 0});

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (pair<int,int> d : dir) {
            int dx = cur.X + d.X;
            int dy = cur.Y + d.Y;
            // pair<int, int> next = {cur.X + d.X, cur.Y + d.Y};
            if (dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
            if (vis[dx][dy] >= 0 || !board[dx][dy]) continue;
            vis[dx][dy] = vis[cur.X][cur.Y] + 1;
            Q.push({dx, dy});
            // cout << "{" << dx << "," << dy << "} -> " <<'\n';
        }
    }

    cout << vis[N-1][M-1] + 1 << '\n';
}