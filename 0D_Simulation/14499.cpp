#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K;
int board[21][21];

int garo[4] = {4, 6, 3, 1};
int sero[4] = {2, 6, 5, 1};

int dice[7];
pair<int,int> roll_dir[5] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void roll(int dir) {
    int dx = x + roll_dir[dir].first;
    int dy = y + roll_dir[dir].second;
    // 지도 바깥으로 나가는 명령은 무시.
    if (dx < 0 || dy < 0 || dx >= N || dy >= M) {
        // cout << dir << " is ignored! / " << "x: " << x << ", y: " << y << '\n';
        return;
    }
    x = dx; 
    y = dy;
    
    int temp;
    switch (dir)
    {
    case 1:
        temp = garo[0];
        for (int i = 0; i < 3; i++) {
            garo[i] = garo[i + 1];
        }
        garo[3] = temp;
        sero[3] = garo[3];
        sero[1] = garo[1];
        break;
    case 2:
        temp = garo[3];
        for (int i = 3; i > 0; i--) {
            garo[i] = garo[i - 1];
        }
        garo[0] = temp;
        sero[3] = garo[3];
        sero[1] = garo[1];
        break;
    case 3:
        temp = sero[3];
        for (int i = 3; i > 0; i--) {
            sero[i] = sero[i - 1];
        }
        sero[0] = temp;
        garo[3] = sero[3];
        garo[1] = sero[1];
        break;
    case 4:
        temp = sero[0];
        for (int i = 0; i < 3; i++) {
            sero[i] = sero[i + 1];
        }
        sero[3] = temp;
        garo[3] = sero[3];
        garo[1] = sero[1];
        break;
    
    default:
        break;
    }

    if (board[x][y] == 0) {
        board[x][y] = dice[sero[1]];
    } else {
        dice[sero[1]] = board[x][y];
        board[x][y] = 0;
    }

    cout << dice[sero[3]] << '\n';
}

int main() {
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int cmd;
        cin >> cmd;

        roll(cmd);
    }


}