#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
pair<int,int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool CheckZero(int board[1002][1002], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j])  {
                 return true;
            }
        }
    }

    return false;
}

int main() {
    int M, N;
    cin >> M >> N;

    queue<pair<int, int>> Q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                Q.push({i, j});
            }
            board[i][j] = a;
        }
    }
    
    pair<int,int> cur;
    while(!Q.empty()) {
        cur = Q.front();  Q.pop();
        for (pair<int,int> d : dir) {
            int dx = cur.X + d.X;
            int dy = cur.Y + d.Y;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if (board[dx][dy] != 0) continue;
            board[dx][dy] = board[cur.X][cur.Y] + 1;
            Q.push({dx, dy});
        }
    }

    if (CheckZero(board, N, M)) {
        cout << "-1" << '\n';
        return 0;
    } else {
        cout << board[cur.X][cur.Y] - 1 << '\n';
        return 0;
    }
}