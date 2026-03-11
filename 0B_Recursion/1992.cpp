#include <bits/stdc++.h>
using namespace std;

string board[64];

bool CheckUnion(int n, int x, int y) {
    char c = board[x][y];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c != board[x + i][y + j])   return false;
        }
    }

    return true;
}

void func(int n, int x, int y) {
    if (n == 1 || CheckUnion(n, x, y)) {
        cout << board[x][y];
        return;
    }
    cout << '(';

    int next_n = n >> 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(next_n, x + i * next_n, y + j * next_n);
        }
    }
    cout << ')';
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    func(N, 0, 0);
}