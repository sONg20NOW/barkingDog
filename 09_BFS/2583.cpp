#include <bits/stdc++.h>
using namespace std;

int board[100][100];
int vis[100][100];
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    vector<int> size;

    while (K--) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int i = lx; i < rx; i++) {
            for (int j = ly; j < ry; j++) {
                board[i][j] = 1;
            }
        }
    }


    queue<pair<int,int>> Q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0 && !vis[i][j]) {
                int sz = 1;

                Q.push({i,j});
                vis[i][j] = 1;
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front();  Q.pop();
                    for (pair<int,int> d : dir) {
                        int dx = d.first + cur.first;
                        int dy = d.second + cur.second;
                        if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
                        if (vis[dx][dy] || board[dx][dy] != 0)  continue;
                        vis[dx][dy] = 1;
                        Q.push({dx,dy});
                        sz++;
                    }
                }

                size.push_back(sz);
            }
        }
    }

    sort(size.begin(), size.end());
    cout << size.size() << '\n';
    for (int sz : size) {
        cout << sz << ' ';
    }

    // cout << "---" << '\n';
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}