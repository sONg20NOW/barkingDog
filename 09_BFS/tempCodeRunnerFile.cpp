#include <bits/stdc++.h>
using namespace std;
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
string board[1000];
int castle_cnt[10];
queue<pair<int,int>> Q[10];

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vector<int> S;
    while (P--) {
        int i;
        cin >> i;
        S.push_back(i);
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        board[i] = s;
        for (int j = 0; j < M; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                Q[board[i][j] - '0'].push({i, j});
                castle_cnt[board[i][j] - '0']++;
            }
        }
    }

    // 시작점
    // for (XY_P k : Q) {
    //     cout << k.player << '-';
    // }
    // cout << '\n';

    while(true) {
        bool moved = false;

        for (int i = 1; i <= S.size(); i++) {
            for (int s = 0; s < S[i - 1]; s++) {
                int size = Q[i].size();
                if (Q[i].empty())   break;
                moved = true;

                while (size--) {
                    pair<int,int> cur = Q[i].front();   Q[i].pop();
                    for (pair<int,int> d : dir) {
                        int dx = d.first + cur.first;
                        int dy = d.second + cur.second;
                        if (dx < 0 || dy < 0 || dx >= N || dy >= M)  continue;
                        if (board[dx][dy] != '.')   continue;

                        board[dx][dy] = i + '0';
                        castle_cnt[i]++;
                        Q[i].push({dx,dy});
                    }

                    // board 상태 표시
                    for (int i = 0; i < N; i++) {
                        cout << board[i] << '\n';
                    }
                    cout << "-----" << "player " << i << '-' << size <<"-----" << '\n';
                }
            }
        }

        if (!moved) break;

        // pair<int,int> cur = Q.front();    Q.pop_front();
        // for (pair<int,int> d : dir) {
        //     int dx = d.first + cur.x;
        //     int dy = d.second + cur.y;
        //     if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
        //     if (board[dx][dy] != '.' || cur.power == 0)   continue;
        //     if (cur.power == 1) {
        //         Q.push_back({dx, dy, cur.player, S[cur.player - 1]});
        //     } else {
        //         Q.push_front({dx, dy, cur.player, cur.power - 1});
        //     }
        //     board[dx][dy] = '0' + cur.player;
        //     castle_cnt[cur.player]++;
        // }

        // board 상태 표시
        // for (int i = 0; i < N; i++) {
        //     cout << board[i] << '\n';
        // }
        // cout << "-----" << '\n';
    }

    for (int i = 1; i <= S.size(); i++) {
        cout << castle_cnt[i] << ' ';
    }
}