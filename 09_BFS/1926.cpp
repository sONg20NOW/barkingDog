#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

pair<int,int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int board[502][502];
int vis[502][502];

int BFS(pair<int, int> start, int n, int m) {
    int size = 1;
    queue<pair<int, int>> Q;
    vis[start.X][start.Y] = 1;
    Q.push(start);
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (pair<int, int> d : dir) {
            int dx = cur.X + d.X;
            int dy = cur.Y + d.Y;
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if (!board[dx][dy] || vis[dx][dy])  continue;
            vis[dx][dy] = 1;
            Q.push({dx, dy});
            size++;
        }
    }

    return size;
};

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            board[i][j] = a;
        }
    }

    int count = 0;
    int max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = board[i][j];
            int v = vis[i][j];

            if (a && !v) {
                // BFS 실행
                int size = BFS({i, j}, n, m);
                max = max < size ? size : max;
                count++;
            }
        }
    }
    cout << count << '\n' << max << '\n';
}