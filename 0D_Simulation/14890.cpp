#include <bits/stdc++.h>
using namespace std;

int N, L;
int board[101][101];

int path;
stack<int> ST;

// 실패하면 0, 성공하면 1 반환.
int canThrough(int i, int column) {
    bool check = false;
    for (int j = 0; j < N; j++) {
        // cout << board[i][j] << "->";
        int cur_h = column ? board[j][i] : board[i][j];
        if (j == 0) {
            while(!ST.empty())  ST.pop();
            ST.push(cur_h);
            continue;
        }
        if (abs(ST.top() - cur_h) > 1)    return 0;
        // 올라가는 경사인 경우
        if (ST.top() < cur_h) {
            if (check && ST.size() < 2 * L) return 0;
            if (ST.size() < L)  return 0;
            while (!ST.empty()) {
                ST.pop();
            }
            check = false;
            ST.push(cur_h);
        } 
        // 내려가는 경사인 경우
        else if (ST.top() > cur_h) {
            if (check && ST.size() < L) return 0;
            while (!ST.empty()) {
                ST.pop();
            }
            check = true;
            ST.push(cur_h);
        } else {
            ST.push(cur_h);
        }
    }

    if (check && ST.size() < L) {
        return 0;
    }
    // cout << (column ? "column " : "row ") << i << '\n';
    return 1;
}

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        // i번째 행에 대해서 탐색
        path += canThrough(i, 0);

        // i번째 열에 대해서 탐색
        path += canThrough(i, 1);
    }

    cout << path << '\n';
}