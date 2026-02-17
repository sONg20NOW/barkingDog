#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
pair<int,int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int,int>> board[101][101];
int vis[101][101];
int light[101][101];

int main() {
    int N, M;
    cin >> N >> M;

    while(M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        board[x][y].push_back({a, b});
    }

    queue<pair<int,int>> Q;
    int cnt = 1;
    vis[1][1] = 1;
    light[1][1] = 1;
    Q.push({1, 1});
    while (!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        
        // 현재 방에서 접근할 수 있는 방들의 스위치 다 켜기
        for (pair<int,int> b : board[cur.X][cur.Y]) {
            if (light[b.X][b.Y])    continue;
            light[b.X][b.Y] = 1;
            // cout << '{' << b.X << ',' << b.Y << "} light up " << '\n';
        
            cnt++;
            // 스위치를 킬 때 인접한 방을 이미 방문했다면 큐에 추가
            for (pair<int,int> d : dir) {
                int dx = d.X + b.X;
                int dy = d.Y + b.Y;
                if (dx < 1 || dy < 1 || dx > N || dy > N) continue;
                if (vis[dx][dy]) {
                    vis[b.X][b.Y] = 1;
                    Q.push({b.X, b.Y});
                }
            } 
        }
        // cout << '{' << cur.X << ',' << cur.Y << "} -> " << cnt << '\n';
        for (pair<int,int> d : dir) {
            int dx = d.X + cur.X;
            int dy = d.Y + cur.Y;
            if (dx < 1 || dy < 1 || dx > N || dy > N) continue;
            if (vis[dx][dy] || !light[dx][dy])  continue;
            vis[dx][dy] = 1;
            Q.push({dx, dy});
        }
    }

    cout << cnt << '\n';
}