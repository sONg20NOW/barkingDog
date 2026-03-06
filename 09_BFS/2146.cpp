#include <bits/stdc++.h>
using namespace std;
int board[100][100];
int vis[100][100];
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int dis[100][100];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int t;
            cin >> t;
            board[i][j] = t;
        }
    }

    // 대륙에 대해서 BFS 진행
    queue<pair<int,int>> Q;

    int region = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] && !vis[i][j]) {
                vis[i][j] = 1;
                board[i][j] = region;
                Q.push({i, j});

                while (!Q.empty()) {
                    pair<int,int> cur = Q.front();  Q.pop();
                    for (pair<int,int> d : dir) {
                        int dx = d.first + cur.first;
                        int dy = d.second + cur.second;

                        if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
                        if (vis[dx][dy] || board[dx][dy] == 0)    continue;
                        vis[dx][dy] = 1;
                        board[dx][dy] = region;
                        Q.push({dx, dy});
                    }
                }
                region++;
            }
        }
    }

    int min_dist = 9999;

    // 각 대륙에 대해서 바다로 확장 시도.
    for (int r = 1; r < region; r++) {
        // 거리 초기화
        for (int i = 0; i < N; i++) {
            fill(dis[i], dis[i] + N, 0);
        }
        // 큐 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == r) {
                    Q.push({i, j});
                    dis[i][j] = 1;
                }
            }
        }
        
        while(!Q.empty()) {
            pair<int,int> cur = Q.front();    Q.pop();
            if (board[cur.first][cur.second] != r && board[cur.first][cur.second] > 0) {
                // cout << "region: " << r << "first: " << cur.first << " second: " << cur.second << '\n';
                min_dist = min(min_dist, dis[cur.first][cur.second]);
                // break하기 전에 큐 비워주기
                while(!Q.empty())   Q.pop();
                break;
            }
            for (pair<int,int> d: dir) {
                int dx = d.first + cur.first;
                int dy = d.second + cur.second;

                if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
                if (board[dx][dy] == r || dis[dx][dy] > 0)   continue;
                Q.push({dx,dy});
                dis[dx][dy] = dis[cur.first][cur.second] + 1;
            }
        }
    }

    cout << min_dist - 2 << '\n';
    
}