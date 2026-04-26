#include <bits/stdc++.h>
using namespace std;

int R, C, T;
int board[51][51];
int temp_board[51][51];

pair<int,int> directions[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
pair<int,int> WindCleaner[2];

void printBoard() {
    cout << "=== print board ===\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int HowManyDust() {
    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] > 0) {
                sum += board[i][j];
            }
        }
    }

    return sum;
}

// r1 -> r2
void MoveDustUp(int k, int r1, int r2) {
    for (int i = r2; i < r1; i++) {
        if (board[i][k] >= 0) {
            board[i][k] = board[i + 1][k];
        }
    }
}

void MoveDustDown(int k, int r1, int r2) {
    for (int i = r2; i > r1; i--) {
        if (board[i][k] >= 0) {
            board[i][k] = board[i - 1][k];
        }
    }
}

// r1 -> r2
void MoveDustRight(int k, int r1, int r2) {
    for (int j = r2; j > r1; j--) {
        board[k][j] = (board[k][j - 1] >= 0 ? board[k][j - 1] : 0);
    }
}

void MoveDustLeft(int k, int r1, int r2) {
    for (int j = r2; j < r1; j++) {
        board[k][j] = board[k][j + 1];
    }
}

// board의 k번째 행을 dir 방향으로 옮기는 함수
// dir - 0 : left, 1: right
void MoveDustRow(int k, int dir) {
    if (dir == 0) {
        for (int j = 0; j < C - 1;  j++) {
            if (board[k][j] >= 0)
                board[k][j] = board[k][j + 1];
        }
    } else {
        for (int i = C - 1; i > 0; i--) {
            if (board[i][k] >= 0)
                board[i][k] = (board[i - 1][k] >= 0 ? board[i - 1][k] : 0);
        }
    }
}

// dir - 0 : 반시계, 1 : 시계
void WindEach(int x, int y, int dir) {
    if (dir == 0) {
        MoveDustDown(0, 0, x);
        MoveDustLeft(0, C-1, 0);
        MoveDustUp(C-1, x, 0);
        MoveDustRight(x, 0, C-1);
    } else {
        MoveDustUp(0, R-1, x);
        MoveDustLeft(R-1, C-1, 0);
        MoveDustDown(C-1, x, R-1);
        MoveDustRight(x, 0, C-1);
    }
}

// board 상에서 순환.
void Wind() {
    for (int i = 0; i < 2; i++) {
        pair<int,int> loc = WindCleaner[i];
        WindEach(loc.first, loc.second, i);
    }
}

void ExtendDust(int i, int j) {
    int extended = 0;
    if (board[i][j] >= 5) {
        int spair = board[i][j] / 5;
        for (pair<int,int> d : directions) {
            int dx = d.first + i;
            int dy = d.second + j;
            if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
            if (board[dx][dy] < 0)  continue;
            temp_board[dx][dy] += spair;
            extended += spair;
        }
    }

    temp_board[i][j] += board[i][j] - extended;
}

// 미세먼지의 확산
void ExtendEveryDust() {
    // temp_board 0으로 초기화
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            temp_board[i][j] = 0;
        }
    }

    // 미세먼지 확산
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ExtendDust(i, j);
        }
    }

    // temp_board -> board
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}

int main() {
    cin >> R >> C >> T;
    int wind_cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] < 0) {
                WindCleaner[wind_cnt++] = {i, j};
            }
        }
    }
    while(T--) {
        ExtendEveryDust();
        Wind();
    }

    cout << HowManyDust();
}