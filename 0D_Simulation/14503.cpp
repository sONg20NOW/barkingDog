#include <bits/stdc++.h>
using namespace std;

int N, M;
int r, c, d;
int board[51][51];
int clean_n;
pair<int,int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};



void vaccumMove() {
    while (true) {
        
        if (board[r][c] == 0) {
            board[r][c] = 2;
            clean_n++;
        }

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;
            int dx = dir[d].first + r;
            int dy = dir[d].second + c;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M)     continue;
            if (board[dx][dy] != 0) continue;
            r = dx;
            c = dy;
            moved = true;
            break;
        }

        if (!moved) {
            int back_d = (d + 2) % 4;
            int dx = dir[back_d].first + r;
            int dy = dir[back_d].second + c;
            if (board[dx][dy] == 1) {
                return;
            }
            r = dx;
            c = dy;
        }
    }
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    vaccumMove();

    cout << clean_n;
}
