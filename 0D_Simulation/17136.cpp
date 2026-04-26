#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int board[N + 4][N + 4];
int min_sum = 101;
int sum = 0;

int remain[6];

bool noOne() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])    return false;
        }
    }

    return true;
}

// (x, y)에 k * k 색종이를 붙일 수 있는지 여부.
int canStick(int x, int y, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (!board[x + i][y + j])   return -1;
        }
    }

    if (remain[k] == 0) return 0;

    return 1;
}

void stick(int x, int y, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            board[x + i][y + j] = 0;
        }
    }
    remain[k]--;
    sum++;
}

void remove(int x, int y, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            board[x + i][y + j] = 1;
        }
    }
    remain[k]++;
    sum--;
}

void func(int n) {
    if (n == 100) {
        if (noOne())
            min_sum = min(min_sum, sum);

        return;
    }

    int x = n / N;
    int y = n % N;
    
    if (board[x][y]) {
        for (int k = 1; k <= 5; k++) {
            int pos = canStick(x, y, k);
            // 종이는 남았지만 붙일 수 없는 경우
            if (pos == -1) {
                break;
            } else if (pos == 0) {
                // 붙일 수는 있지만 종이가 없는 경우
                continue;
            }
            stick(x, y, k);
            func(n + 1);
            remove(x, y, k);
        }
    } else {
        func(n + 1);
    }
    
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    fill(remain, remain + 6, 5);

    func(0);

    cout << (min_sum == 101 ? -1 : min_sum);
}