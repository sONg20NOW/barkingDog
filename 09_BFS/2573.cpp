#include <bits/stdc++.h>
using namespace std;

int board[300][300];
int vis[300][300];
int adj_water[300][300];
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool Check_melt(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 0)   return false;
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int time = 0;

    queue<pair<int,int>> Q;

    while(true) {
        if (Check_melt(N, M))   break;

        int piece = 0;

        // cout << "-----" << '\n';

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // BFS 진행
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] > 0 && !vis[i][j]) {
                    if (piece > 0) {
                        cout << time << '\n';
                        return 0;
                    }
                    Q.push({i,j});
                    vis[i][j] = 1;
                    while(!Q.empty()) {
                        pair<int,int> cur = Q.front();  Q.pop();
                        for (pair<int,int> d : dir) {
                            int dx = d.first + cur.first;
                            int dy = d.second + cur.second;
                            if (dx < 0 || dy < 0 || dx >= N || dy >= M ) continue;
                            if (board[dx][dy] == 0)  {
                                adj_water[cur.first][cur.second]++;
                                continue;
                            }
                            if (vis[dx][dy]) continue;

                            Q.push({dx,dy});
                            vis[dx][dy] = 1;
                        }
                    }
                    piece++;
                }
            }
        }

        // 얼음 녹이기 + 시간 진행 + vis 배열 초기화 + adj_water 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j]) {
                    board[i][j] = max(0, board[i][j] - adj_water[i][j]);
                }
            }
            fill(vis[i], vis[i] + 300, 0);
            fill(adj_water[i], adj_water[i] + 300, 0);
        }
        time++;
    }

    cout << 0 << '\n';
    return 0;
}