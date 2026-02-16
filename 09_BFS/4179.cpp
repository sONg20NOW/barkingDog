#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int time_F[1002][1002];
int time_J[1002][1002];
pair<int,int> dir[4] = {{1, 0}, {-1, 0} ,{0, 1}, {0, -1}};

int main() {
    int R, C;
    cin >> R >> C;

    queue<pair<int, int>> FireQ;
    queue<pair<int, int>> JihoonQ;

    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        board[i] = row;

        for (int j = 0; j < C; j++) {
            if (row[j] == 'F') {
                time_F[i][j] = 1;
                FireQ.push({i, j});
            } else if (row[j] == 'J') {
                time_J[i][j] = 1;
                JihoonQ.push({i, j});
            }
        }
    }

    // 불길의 경로 먼저 계산 - BFS
    while(!FireQ.empty()) {
        pair<int, int> cur = FireQ.front(); FireQ.pop();
        for (pair<int, int> d : dir) {
            int dx = d.X + cur.X;
            int dy = d.Y + cur.Y;
            if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
            if (board[dx][dy] == '#' || time_F[dx][dy] > 0)  continue;
            time_F[dx][dy] = time_F[cur.X][cur.Y] + 1;
            FireQ.push({dx, dy});
        }
    }

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << time_F[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // 그 다음 지훈의 경로 계산 - 단, 진행 조건에 다음 시간이 그 자리의 불 도착 시간보다 작아야 된다는 것을 추가
    while(!JihoonQ.empty()) {
        pair<int, int> cur = JihoonQ.front(); JihoonQ.pop();
        if (cur.X == 0 || cur.Y == 0 || cur.X == R - 1 || cur.Y == C - 1) {
            cout << time_J[cur.X][cur.Y] << '\n';
            return 0;
        }
        for (pair<int, int> d : dir) {
            int dx = d.X + cur.X;
            int dy = d.Y + cur.Y;
            if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
            if (board[dx][dy] != '.' || time_J[dx][dy] > 0 || (time_F[dx][dy] && time_F[dx][dy] <= time_J[cur.X][cur.Y] + 1))  continue;
            time_J[dx][dy] = time_J[cur.X][cur.Y] + 1;
            // if (dx == 0 || dy == 0 || dx == R - 1 || dy == C - 1) {
            //     cout << time_J[dx][dy] << '\n';
            //     return 0;
            // }
            JihoonQ.push({dx, dy});
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}