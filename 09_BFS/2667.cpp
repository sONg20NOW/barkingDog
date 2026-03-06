#include <bits/stdc++.h>
using namespace std;
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
string board[25];
int vis[25][25];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    vector<int> sizes;

    queue<pair<int,int>> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '1' && !vis[i][j]) {
                int sz = 1;

                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front();  Q.pop();
                    for (pair<int,int> d: dir) {
                        int dx = d.first + cur.first;
                        int dy = d.second + cur.second;
                        if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
                        if (vis[dx][dy] || board[dx][dy] == '0')    continue;
                        vis[dx][dy] = 1;
                        Q.push({dx,dy});
                        sz++;
                    }
                }

                sizes.push_back(sz);
            }
        }
    }

    cout << sizes.size() << '\n';
    sort(sizes.begin(), sizes.end());
    for (int sz : sizes) {
        cout << sz << '\n';
    }
}