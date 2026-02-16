#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;

        int board[50][50];
        for (int* row : board) {
            fill(row, row+50, 0);
        }

        int vis[50][50];
        for (int* row : vis) {
            fill(row, row+50, 0);
        }
        while (K--) {
            int a, b;
            cin >> a >> b;
            board[b][a] = 1;
        }

        queue<pair<int,int>> Q;
        int count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!vis[i][j] && board[i][j]) {
                    count++;
                    vis[i][j] = 1;
                    Q.push({i, j});
                    while(!Q.empty()) {
                        pair<int,int> cur = Q.front();  Q.pop();
                        for (pair<int,int> d : dir) {
                            int dx = cur.x + d.x;
                            int dy = cur.y + d.y;
                            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
                            if (vis[dx][dy] || !board[dx][dy])    continue;
                            vis[dx][dy] = 1;
                            Q.push({dx, dy});
                        }
                    }
                }
            }
        }

        cout << count << '\n';
    }
}