#include <bits/stdc++.h>
using namespace std;
pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
string board[1000];
int castle_cnt[10];

struct XY_P {
    int x, y, player, power;
};

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
    }

    // Q에 사용자 순서대로 시작점 넣기 O(M * N^2)
    deque<XY_P> Q;
    for (int p = 0; p < S.size(); p++) {
        char player = '1' + p;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == player) {
                    Q.push_back({i, j, p + 1, S[p]});
                    castle_cnt[p + 1]++;
                }
            }
        }
    }

    // 시작점
    // for (XY_P k : Q) {
    //     cout << k.player << '-';
    // }
    // cout << '\n';

    while(!Q.empty()) {
        XY_P cur = Q.front();    Q.pop_front();
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.x;
            int dy = d.second + cur.y;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if (board[dx][dy] != '.' || cur.power == 0)   continue;
            if (cur.power == 1) {
                Q.push_back({dx, dy, cur.player, S[cur.player - 1]});
            } else {
                Q.push_front({dx, dy, cur.player, cur.power - 1});
            }
            board[dx][dy] = '0' + cur.player;
            castle_cnt[cur.player]++;
        }

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