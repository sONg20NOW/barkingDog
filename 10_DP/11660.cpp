#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MX = 1024 + 1;
int board[MX][MX];
int D[MX][MX];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int j = 1; j <= N; j++) {
        D[1][j] = D[1][j-1] + board[1][j];
        D[j][1] = D[j-1][1] + board[j][1];
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            D[i][j] = D[i-1][j] + D[i][j-1] - D[i-1][j-1] + board[i][j];
        }
    }

    while (M--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = D[x2][y2] - D[x2][y1-1] - D[x1-1][y2] + D[x1-1][y1-1];
        cout << ans << '\n';
    }
}