#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[100];
int vis[100][100];
int vis_D[100][100];
pair<int,int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool CheckSame(char A, char B) {
    if (A == 'R' || A == 'G') {
        if (B == 'R' || B == 'G')   return true;
        else    return false;
    } else {
        if (B == 'B')   return true;
        else    return false;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        board[i] = s;
    }

    int normal_cnt = 0;
    int d_cnt = 0;
    // 정상인 BFS
    queue<pair<int,int>> Q;
    queue<pair<int,int>> Q_D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) {
                vis[i][j] = 1;
                Q.push({i, j});
                normal_cnt++;
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front();  Q.pop();
                    for (pair<int,int> d : dir) {
                        int dx = d.X + cur.X;
                        int dy = d.Y + cur.Y;
                        if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
                        if (vis[dx][dy] || board[cur.X][cur.Y] != board[dx][dy])    continue;
                        vis[dx][dy] = 1;
                        Q.push({dx, dy});
                    }
                }
            }

            if (!vis_D[i][j]) {
                vis_D[i][j] = 1;
                Q_D.push({i, j});
                d_cnt++;
                while(!Q_D.empty()) {
                    pair<int,int> cur = Q_D.front();  Q_D.pop();
                    for (pair<int,int> d : dir) {
                        int dx = d.X + cur.X;
                        int dy = d.Y + cur.Y;
                        if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
                        if (vis_D[dx][dy] || !CheckSame(board[cur.X][cur.Y], board[dx][dy]))    continue;
                        vis_D[dx][dy] = 1;
                        Q_D.push({dx, dy});
                    }
                }
            }
        }
    }

    cout << normal_cnt << ' ' << d_cnt << '\n';
}