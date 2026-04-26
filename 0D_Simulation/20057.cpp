#include <bits/stdc++.h>
using namespace std;

int N;
int board[500][500];
const pair<int,int> dirs[4] = {{0,-1}, {1,0}, {0,1}, {-1,0}};

int out_sand = 0;

// 범위에서 벗어나면 true 반환
bool OOB(int r, int c) {
    return (r < 0 || c < 0 || r >= N || c >= N);
}

void printBoard() {
    cout << " === print board ===\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void innerFunc(int r, int c, int dir, int init_sand, int percentage) {
    int shared_sand = init_sand * percentage / 100;
    int op_dir = (dir + 2) % 4;

    // 0이면 가로축(왼/오), 1이면 세로축(상/하)
    bool axis = dir % 2;

    int dx = r;
    int dy = c;

    int diff = 1;
    switch (percentage)
    {
    case 1:
        dx += dirs[op_dir].first;
        dy += dirs[op_dir].second;
        break;
    case 2:
        diff = 2;
        break;
    case 7:
        break;
    case 55:
    case 10:
        dx += dirs[dir].first;
        dy += dirs[dir].second;
        break;
    case 5:
        dx += dirs[dir].first * 2;
        dy += dirs[dir].second * 2;
        break;
    default:
        break;
    }

    if (percentage == 5 || percentage == 55) {
        if (percentage == 55) {
            shared_sand = board[r][c];
        }

        if (OOB(dx, dy)) {
            out_sand += shared_sand;
        } else {
            board[dx][dy] += shared_sand;
        }
        board[r][c] -= shared_sand;
    } else {
        for (int i : {-1 * diff, diff}) {
            int t_dx = dx;
            int t_dy = dy;
            if (axis == 0) {
                t_dx += i;
            } else {
                t_dy += i;
            }

            if (OOB(t_dx, t_dy)) {
                out_sand += shared_sand;
            } else {
                board[t_dx][t_dy] += shared_sand;
            }
            board[r][c] -= shared_sand;
        }
    }
}

// (r,c)로 토네이도가 왔을 때 처리하는 함수
void func(int r, int c, int dir) {
    
    int init_sand = board[r][c];

    innerFunc(r, c, dir, init_sand, 1);
    innerFunc(r, c, dir, init_sand, 2);
    innerFunc(r, c, dir, init_sand, 7);
    innerFunc(r, c, dir, init_sand, 10);
    innerFunc(r, c, dir, init_sand, 5);
    innerFunc(r, c, dir, init_sand, 55);
    // printBoard();

}

void progress() {
    int x = N / 2;
    int y = N / 2;
    int dir = 0;
    int prev_dir = 0;
    int k = 1;
    int repeat = 2;
    int step = k;
    while (!(x == 0 && y == -1)) {
        if (step == 0) {
            repeat--;
            dir = (dir + 1) % 4;
            step = k;
        }
        if (repeat == 0) {
            repeat = 2;
            k++;
            step = k;
        }
        func(x, y, prev_dir);
        x = dirs[dir].first + x;
        y = dirs[dir].second + y;
        step--;
        prev_dir = dir;
    }
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    progress();

    cout << out_sand;
}