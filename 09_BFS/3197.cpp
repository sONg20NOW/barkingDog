#include <bits/stdc++.h>
using namespace std;

const int MX = 1500;
string board[MX];
int vis[MX][MX];
int when_melt[MX][MX];
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void Melt(int R, int C) {
    queue<pair<int,int>> Q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            when_melt[i][j] = -1;
            if (board[i][j] == '.' || board[i][j] == 'L') {
                Q.push({i,j});
                when_melt[i][j] = 0;
            }
        }
    }

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
            if (when_melt[dx][dy] >= 0 || board[dx][dy] == 'L') continue;
            when_melt[dx][dy] = when_melt[cur.first][cur.second] + 1;
            Q.push({dx,dy});
        }
    }

    // cout << "when melt?" << '\n';
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << when_melt[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

int main() {
    int R, C;
    cin >> R >> C;

    queue<pair<int,int>> ICED[MX];
    queue<pair<int,int>> Q;

    bool once = true;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        if (once) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'L') {
                    Q.push({i,j});
                    // cout << "pushed(init): " << i << ',' << j << '\n';

                    vis[i][j] = 1;
                    once = false;
                    break;
                }
            }
        }
    }
    
    Melt(R, C);

    int day = 0;
    while (true) {
        // 녹은 애들 큐에 넣기
        if (day > 0) {
            while(!ICED[day].empty()) {
                pair<int,int> cur = ICED[day].front();  ICED[day].pop();
                Q.push({cur.first, cur.second});
            }
        }
        while(!Q.empty()) {
            pair<int,int> cur = Q.front();  Q.pop();
            // cout << "day: " << day << " / cur: " << cur.first << ',' << cur.second << '\n';
            if (board[cur.first][cur.second] == 'L') {
                if (!once)  once = true;
                else {
                    cout << day << '\n';
                    return 0;
                }
            }
            for (pair<int,int> d : dir) {
                int dx = d.first + cur.first;
                int dy = d.second + cur.second;
                if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
                if (vis[dx][dy])    continue;
                if (board[dx][dy] == 'X' && when_melt[dx][dy] > day) {
                    ICED[when_melt[dx][dy]].push({dx,dy});
                    vis[dx][dy] = 1;
                    continue;
                } 
                Q.push({dx,dy});
                // cout << "pushed: " << dx << ',' << dy << '\n';
                vis[dx][dy] = 1;
                
            }
        }
        day++;
    }

}