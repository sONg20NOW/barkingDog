#include <bits/stdc++.h>
using namespace std;
int board[100][100];
int vis[100][100];
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int main() {
    int N;
    cin >> N;
    
    int max_h = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            max_h = max(max_h, board[i][j]);
        }
    }

    int water_h = 0;
    int max_cnt = 1;
    queue<pair<int,int>> Q;
    
    while(++water_h < max_h) {
        // vis 배열 초기화 && Q 초기화
        for (int i = 0; i < N; i++) {
            fill(vis[i], vis[i] + 100, 0);
        }
        while(!Q.empty())   Q.pop();

        int cnt = 0;
        // 보드를 돌면서 잠기지 않은 부분에 대해서 BFS 진행.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] > water_h && !vis[i][j]) {
                    Q.push({i, j});
                    vis[i][j] = 1;
                    while(!Q.empty()) {
                        pair<int,int> cur = Q.front();  Q.pop();
                        for (pair<int,int> d : dir) {
                            int dx = d.first + cur.first;
                            int dy = d.second + cur.second;

                            if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
                            if (vis[dx][dy] || board[dx][dy] <= water_h)    continue;
                            Q.push({dx,dy});
                            vis[dx][dy] = 1;
                        }
                    }
                    cnt++;
                }
            }
        }

        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt << '\n';
}