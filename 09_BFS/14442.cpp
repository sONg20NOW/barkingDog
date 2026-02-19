#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
string board[1001];
int vis[1002][1002][11];

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        board[i] = s;
    }

    queue<pair<int,int>> Q;
    vis[1][1][0] = 1;
    Q.push({0,0});
    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        if (cur == target) {
            cout << dis[cur.X][cur.Y] << '\n';
            return 0;
        }
        for (pair<int,int> d : dir) {
            int dx = d.X + cur.X;
            int dy = d.Y + cur.Y;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if (wall_cnt[dx][dy] >= 0 || dis[dx][dy] >= 0 || (board[dx][dy] == '1' && wall_cnt[cur.X][cur.Y] + 1 > K))  continue;
            wall_cnt[dx][dy] = board[dx][dy] ? wall_cnt[cur.X][cur.Y] + 1 : wall_cnt[cur.X][cur.Y];
            dis[dx][dy] = dis[cur.X][cur.Y] + 1;
        }
    }
}