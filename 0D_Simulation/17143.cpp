#include <bits/stdc++.h>
using namespace std;

int R, C, M;
struct Shark {
    int speed, dir, size;
};
Shark board[101][101];
Shark temp_board[101][101];

pair<int,int> move_directions[5] = {{}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int size_sum;

// col열에 있는 지면에서 가장 가까운 상어 잡기
void FishingShark(int col) {
    for (int i = 0; i < R; i++) {
        Shark s = board[i][col];
        if (s.size > 0) {
            size_sum += s.size;
            board[i][col] = {0, 0, 0};
            return;
        }
    }
}

// 위치를 구해서 이동시키기(temp_board에 기록)
void MoveShark(int r, int c, Shark s) {
    int speed = s.speed;
    int dir = s.dir;
    int dx = r + move_directions[s.dir].first * s.speed;
    int dy = c + move_directions[s.dir].second * s.speed;

    while (dx < 0 || dy < 0 || dx >= R || dy >= C) {
        switch (dir)
        {
        case 1:
            dx = -dx;
            dir = 2;
            break;
        case 2:
            dx = (R - 1) - (dx - (R - 1));
            dir = 1;
            break;
        case 3:
            dy = (C - 1) - (dy - (C - 1));
            dir = 4;
            break;
        case 4:
            dy = -dy;
            dir = 3;
            break;
        
        default:
            break;
        }
    }

    // // 상어 이동시키기
    // while (speed) {
    //     dx += move_directions[dir].first;
    //     dy += move_directions[dir].second;
    //     // 다음 위치가 보드를 벗어나면 방향 전환
    //     if (dx < 0 || dy < 0 || dx >= R || dy >= C) {
    //         dx -= move_directions[dir].first;
    //         dy -= move_directions[dir].second;
    //         if (dir % 2 == 0) {
    //             dir--;
    //         } else {
    //             dir++;
    //         }

    //         continue;
    //     }
    //     speed--;
    // }

    // 해당 칸에 이미 상어가 있는지 확인
    if (temp_board[dx][dy].size > s.size) {
        return;
    } else {
        temp_board[dx][dy] = {s.speed, dir, s.size};
    }
    
}

// 모든 칸에 있는 상어 이동시키기
void MoveSharks() {
    // temp_board 초기화
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            temp_board[i][j] = {0, 0, 0};
        }
    }

    // board에 있는 상어들 temp_board로 이동시키기
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            Shark s = board[i][j];
            if (s.size > 0) {
                MoveShark(i, j, s);
            }
        }
    }

    // temp_board -> board 복사
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] =  temp_board[i][j];
        }
    }
}

int main() {
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r - 1][c - 1] = {s, d, z};
    }

    for (int col = 0; col < C; col++) {
        // 상어 잡기
        FishingShark(col);

        // 상어 이동
        MoveSharks();
    }

    cout << size_sum;
}