#include <bits/stdc++.h>
using namespace std;

const int MX = 6561;
char board[MX][MX];

// loc : 1 ~ 9 중 하나
void func(int n, int loc, int x, int y) {
    // cout << "n: " << n << ", loc: " << loc << ", x: " << x << ", y: " << y << '\n';
    if (loc == 5) {
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                board[i][j] = ' ';
            }
        }
        return;
    } else if (n == 1) {
        board[x][y] = '*';
        return;
    }

    int next_n = n / 3;
    int box = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            func(next_n, box++, x + i * next_n, y + j * next_n);
        }
    }
}

int main() {
    int N;
    cin >> N;

    func(N, 1, 0, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}