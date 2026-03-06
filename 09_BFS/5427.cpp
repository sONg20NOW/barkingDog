#include <bits/stdc++.h>
using namespace std;
const int MX = 1000;
string board[MX];
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int timeF[MX][MX];
int timeS[MX][MX];
queue<pair<int,int>> Q_F;
queue<pair<int,int>> Q;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int w, h;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            cin >> board[i];
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '*') {
                    Q_F.push({i, j});
                    timeF[i][j] = 1;
                }
                else if (board[i][j] == '@') {
                    Q.push({i, j});
                    timeS[i][j] = 1;
                }
            }
        }

        // cout << "---FIRE (INIT)---" << '\n';
        // for (int i = 0; i < h; i++) {
        //     for (int j = 0; j < w; j++) {
        //         cout << timeF[i][j] << ' ';
        //     }AC
        //     cout << '\n';
        // }

        // 불 BFS 먼저 진행
        while(!Q_F.empty()) {
            pair<int,int> cur = Q_F.front();    Q_F.pop();
            for (pair<int,int> d : dir) {
                int dx = d.first + cur.first;
                int dy = d.second + cur.second;
                if (dx < 0 || dy < 0 || dx >= h || dy >= w) continue;
                if (timeF[dx][dy] || board[dx][dy] == '#') continue;
                timeF[dx][dy] = timeF[cur.first][cur.second] + 1;
                Q_F.push({dx,dy});
            }
        }

        // cout << "---FIRE---" << '\n';
        // for (int i = 0; i < h; i++) {
        //     for (int j = 0; j < w; j++) {
        //         cout << timeF[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        // 상근이 BFS 진행
        bool imps = true;

        // cout << "---Sanguen(INIT)---" << '\n';
        // for (int i = 0; i < h; i++) {
        //     for (int j = 0; j < w; j++) {
        //         cout << timeS[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        while(!Q.empty()) {
            pair<int,int> cur = Q.front();  Q.pop();
            // cout << "{" << cur.first << ',' << cur.second << "} -> "<< '\n';
            if (cur.first == 0 || cur.second == 0 || cur.first == h - 1 || cur.second == w - 1) {
                cout << timeS[cur.first][cur.second] << '\n';
                imps = false;
                break;
            }
            for (pair<int,int> d : dir) {
                int dx = d.first + cur.first;
                int dy = d.second + cur.second;
                if (dx < 0 || dy < 0 || dx >= h || dy >= w) continue;
                if (timeS[dx][dy] || board[dx][dy] != '.') continue;
                if (timeF[dx][dy] != 0 && timeS[cur.first][cur.second] + 1 >= timeF[dx][dy]) continue;
                timeS[dx][dy] = timeS[cur.first][cur.second] + 1;
                Q.push({dx,dy});
            }
        }

        // cout << "---Sanguen---" << '\n';
        // for (int i = 0; i < h; i++) {
        //     for (int j = 0; j < w; j++) {
        //         cout << timeS[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        if (imps)   cout << "IMPOSSIBLE" << '\n';

        // time 초기화. Q 초기화
        for (int i = 0; i < h; i++) {
            fill(timeF[i], timeF[i] + MX, 0);
            fill(timeS[i], timeS[i] + MX, 0);
        }
        while(!Q.empty())   Q.pop();
        while(!Q_F.empty())   Q_F.pop();

    }
}