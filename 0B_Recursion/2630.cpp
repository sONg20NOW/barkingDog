#include <bits/stdc++.h>
using namespace std;

const int MX = 128;
int board[MX][MX];

int paper_cnt[2];

bool CheckUnion(int N, int x, int y) {
    if (N == 1) return true;

    int standard = board[x][y];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (standard != board[x + i][y + j])    return false;
        }
    }

    return true;
}

void func(int N, int x, int y) {
    if (CheckUnion(N, x, y)) {
        paper_cnt[board[x][y]]++;
        return;
    }

    int next_N = N / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(next_N, x + i * next_N, y + j * next_N);
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    func(N, 0, 0);

    for (int i : paper_cnt) {
        cout << i << '\n';
    }

}