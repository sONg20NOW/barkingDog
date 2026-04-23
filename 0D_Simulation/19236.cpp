#include <bits/stdc++.h>
using namespace std;

const pair<int,int> dirs[8] = {
    {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}
};
struct Fish {
    int r, c, dir;
    bool dead;
};
// 0: 상어, 1~16: 물고기
Fish fishes[17];


// 각 칸에 있는 물고기의 번호 (상어는 -1, 빈칸은 0)
int board[4][4];

int max_sum = -1;

void printBoard() {
    cout << "=== print board ===\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

// idx번 물고기를 옮기기
void moveEachFish(int idx) {
    if (fishes[idx].dead)   return;
    int dir = fishes[idx].dir;
    do {
        int dx = fishes[idx].r + dirs[dir].first;
        int dy = fishes[idx].c + dirs[dir].second;

        if (dx < 0 || dy < 0 || dx >= 4 || dy >= 4 || board[dx][dy] == -1) {
            dir = (dir + 1) % 8;
            continue;
        }

        // 옮길 수 있으면 해당 방향의 물고기와 위치 바꾸기
        int target = board[dx][dy];
        if (target > 0) {
            fishes[target] = {fishes[idx].r, fishes[idx].c, fishes[target].dir, false};
            board[fishes[idx].r][fishes[idx].c] = target;
        } else {
            board[fishes[idx].r][fishes[idx].c] = 0;
        }
        fishes[idx] = {dx, dy, dir, false};
        board[dx][dy] = idx;

        break;
    } while (dir != fishes[idx].dir);
}

void moveAllFish() {
    for (int i = 1; i <= 16; i++) {
        moveEachFish(i);
    }
}

void func(int sum) {
    max_sum = max(max_sum, sum);

    // 물고기 이동
    moveAllFish();
    int temp_board[4][4];
    Fish temp_fishes[17];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp_board[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < 17; i++) {
        temp_fishes[i] = fishes[i];
    }

    for (int step = 1; step <= 3; step++) {

        int dx = fishes[0].r + dirs[fishes[0].dir].first * step;
        int dy = fishes[0].c + dirs[fishes[0].dir].second * step;
        int target = board[dx][dy];

        // 상어가 진행할 수 없으면 다음 step으로
        if (dx < 0 || dy < 0 || dx >= 4 || dy >= 4 || target <= 0) {
            continue;
        }

        // 상어 이동
        fishes[target].dead = true;
        board[fishes[0].r][fishes[0].c] = 0;
        board[dx][dy] = -1;

        fishes[0] = {dx, dy, fishes[target].dir, false};

        func(sum + target);

        // 진행 전 상태로 복구
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = temp_board[i][j];
            }
        }

        for (int i = 0; i < 17; i++) {
            fishes[i] = temp_fishes[i];
        }
    }
}


int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            fishes[a] = {i, j, b-1, false};
            board[i][j] = a;
        }
    }
    // (0,0)에 있는 물고기 먹기
    int fish_num = board[0][0];
    fishes[fish_num].dead = true;
    board[0][0] = -1;
    fishes[0] = {0, 0, fishes[fish_num].dir, false};

    func(fish_num);

    cout << max_sum;
}