#include <bits/stdc++.h>
using namespace std;

int N;
int can_put[10][10];

int max_black_cnt;
int max_white_cnt;

// 갈 수 없는 x+y 값
int x_plus_y[18];

// 갈 수 없는 N - 1 + (x-y) 값
int x_minus_y[18];

// x 행의 k 번째 칸 진행 중 (홀수 칸에 대해) (현재 비숍 b_cnt개)
void func_black(int x, int k, int b_cnt) {
    // cout << "k: " << k << ", b_cnt : " << b_cnt << '\n';
    if (x == N) {
        max_black_cnt = max(max_black_cnt, b_cnt);
        return;
    }

    // 한 행에 최대 (N + 1) / 2개
    // N이 홀수라면 홀수행에는 (N + 1) / 2 - 1개
    int max_row_cnt = (N + 1) / 2;

    int y = (x % 2 == 1 ? 1 : 0) + k * 2;

    bool can = true;
    if (can_put[x][y] == 0 || x_plus_y[x + y] || x_minus_y[x - y + N - 1])   
        can = false;

    if (can) {
        x_plus_y[x + y] = 1;
        x_minus_y[x - y + N - 1] = 1;
        if (N % 2 == 0) {
            if (k == max_row_cnt - 1)   func_black(x + 1, 0, b_cnt + 1);
            else    func_black(x, k + 1, b_cnt + 1);
        } else {
            if (x % 2 == 0) {
                if (k == max_row_cnt - 1)   func_black(x + 1, 0, b_cnt + 1);
                else    func_black(x, k + 1, b_cnt + 1);
            } else {
                if (k == max_row_cnt - 2)   func_black(x + 1, 0, b_cnt + 1);
                else    func_black(x, k + 1, b_cnt + 1);
            }
        }
        x_plus_y[x + y] = 0;
        x_minus_y[x - y + N - 1] = 0;
    }
    if (N % 2 == 0) {
        if (k == max_row_cnt - 1)   func_black(x + 1, 0, b_cnt);
        else    func_black(x, k + 1, b_cnt);
    } else {
        if (x % 2 == 0) {
            if (k == max_row_cnt - 1)   func_black(x + 1, 0, b_cnt);
            else    func_black(x, k + 1, b_cnt);
        } else {
            if (k == max_row_cnt - 2)   func_black(x + 1, 0, b_cnt);
            else    func_black(x, k + 1, b_cnt);
        }
    }
}

// k번째 칸 진행 중 (짝수 칸에 대해) (현재 비숍 b_cnt개)
void func_white(int x, int k, int b_cnt) {
    // cout << "k: " << k << ", b_cnt : " << b_cnt << '\n';
    if (x == N) {
        max_white_cnt = max(max_white_cnt, b_cnt);
        return;
    }

    // 한 행에 최대 (N + 1) / 2개
    // N이 홀수라면 짝수행에는 (N + 1) / 2 - 1개
    int max_row_cnt = (N + 1) / 2;

    int y = (x % 2 == 0 ? 1 : 0) + k * 2;

    bool can = true;
    if (can_put[x][y] == 0 || x_plus_y[x + y] || x_minus_y[x - y + N - 1])   
        can = false;

    if (can) {
        x_plus_y[x + y] = 1;
        x_minus_y[x - y + N - 1] = 1;
        if (N % 2 == 0) {
            if (k == max_row_cnt - 1)   func_white(x + 1, 0, b_cnt + 1);
            else    func_white(x, k + 1, b_cnt + 1);
        } else {
            if (x % 2 == 1) {
                if (k == max_row_cnt - 1)   func_white(x + 1, 0, b_cnt + 1);
                else    func_white(x, k + 1, b_cnt + 1);
            } else {
                if (k == max_row_cnt - 2)   func_white(x + 1, 0, b_cnt + 1);
                else    func_white(x, k + 1, b_cnt + 1);
            }
        }
        x_plus_y[x + y] = 0;
        x_minus_y[x - y + N - 1] = 0;
    }
    if (N % 2 == 0) {
        if (k == max_row_cnt - 1)   func_white(x + 1, 0, b_cnt);
        else    func_white(x, k + 1, b_cnt);
    } else {
        if (x % 2 == 1) {
            if (k == max_row_cnt - 1)   func_white(x + 1, 0, b_cnt);
            else    func_white(x, k + 1, b_cnt);
        } else {
            if (k == max_row_cnt - 2)   func_white(x + 1, 0, b_cnt);
            else    func_white(x, k + 1, b_cnt);
        }
    }
}

// color 0은 짝수칸, 1은 홀수칸
void func(int x, int y, int b_cnt, int color) {
    if (y >= N) {
        x++;
        y = (color == 0) ? (x % 2 == 0 ? 0 : 1) : (x % 2 == 0 ? 1 : 0);
    }

    if (x >= N) {
        if (color == 0) max_black_cnt = max(max_black_cnt, b_cnt);
        else max_white_cnt = max(max_white_cnt, b_cnt);

        return;
    }

    if (can_put[x][y] == 1 && !x_plus_y[x + y] && !x_minus_y[x - y + N - 1]) {
        x_plus_y[x + y] = 1;
        x_minus_y[x - y + N - 1] = 1;
        func(x, y + 2, b_cnt + 1, color);
        x_plus_y[x + y] = 0;
        x_minus_y[x - y + N - 1] = 0;
    }   

    func(x, y + 2, b_cnt, color);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> can_put[i][j];
        }
    }

    func(0, 0, 0, 0);
    func(0, 1, 0, 1);

    cout << max_black_cnt + max_white_cnt;
}