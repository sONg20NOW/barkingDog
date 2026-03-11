#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int paper_cnt[3];

bool CheckUnion(int n, int dx, int dy) {
    int t = board[dx][dy];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (t != board[dx + i][dy + j])   return false;
        }
    }

    return true;
}

// n : 한 변의 길이, dx : 시작점으로부터의 거리, dy : 시작점으로부터의 거리
void func(int n, int dx, int dy) {
    if (n == 1 || CheckUnion(n, dx, dy)) {
        int t = board[dx][dy];
        // cout << "n: " << n << ", dx: " << dx << ", dy: " << dy << '\n';
        paper_cnt[1 + t] ++;
        return;
    }
    int next_n = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            func(next_n, dx + next_n * i, dy + next_n * j);
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