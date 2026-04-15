#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int board[100][100];
int N = 3;
int M = 3;
int cnt[101];
vector<pair<int,int>> num_cnt;

void printBoard() {
    cout << "=== board ===\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool compareR(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

// R연산
void sortR() {
    int next_M = M;
    for (int i = 0; i < N; i++) {
        while(!num_cnt.empty()) num_cnt.pop_back();
        fill(cnt, cnt + 101, 0);

        for (int j = 0; j < M; j++) {
            cnt[board[i][j]]++;
        }

        for (int n = 1; n <= 100; n++) {
            if (cnt[n] > 0)
                num_cnt.push_back({n, cnt[n]});
        }

        sort(num_cnt.begin(), num_cnt.end(), compareR);
        int row_size = min(100, int(num_cnt.size() * 2));
        next_M = max(next_M, row_size);
        for (int j = 0; j < next_M; j++) {
            if (j >= row_size) {
                board[i][j] = 0;
                continue;
            }

            if (j % 2 == 0) {
                board[i][j] = num_cnt[j / 2].first;
            } else {
                board[i][j] = num_cnt[j / 2].second;
            }
        }
    }
    M = next_M;
}

// C 연산
void sortC() {
    int next_N = N;
    for (int j = 0; j < M; j++) {
        while(!num_cnt.empty()) num_cnt.pop_back();
        fill(cnt, cnt + 101, 0);

        for (int i = 0; i < N; i++) {
            cnt[board[i][j]]++;
        }

        for (int n = 1; n <= 100; n++) {
            if (cnt[n] > 0)
                num_cnt.push_back({n, cnt[n]});
        }

        sort(num_cnt.begin(), num_cnt.end(), compareR);
        int column_size = min(100, int(num_cnt.size() * 2));
        next_N = max(next_N, column_size);
        for (int i = 0; i < next_N; i++) {
            if (i >= column_size) {
                board[i][j] = 0;
                continue;
            }

            if (i % 2 == 0) {
                board[i][j] = num_cnt[i / 2].first;
            } else {
                board[i][j] = num_cnt[i / 2].second;
            }
        }
    }
    N = next_N;
}

void func() {
    if (N >= M) {
        sortR();
    } else {
        sortC();
    }
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int t = 0;
    while(true) {
        if (t > 100) {
            cout << - 1 << '\n';
            return 0;
        }
        if (board[r - 1][c - 1] == k)   break;
        func();
        t++;
    }

    cout << t;
}