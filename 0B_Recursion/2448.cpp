#include <bits/stdc++.h>
using namespace std;

const int MX = 3072;
const int MY = 6143;
char board[MX][MY];

// x, y는 맨위 꼭짓점의 위치
void func(int x, int y, int h) {
    if (h == 3) {
        pair<int,int> triangle[8] = {
            {0,0},
            {1,-1}, {1,1},
            {2,-2}, {2,-1}, {2,0}, {2,1}, {2,2}
        };
        for (pair<int,int> p : triangle) {
            board[x + p.first][y + p.second] = '*';
        }
        return;
    } 

    int next_h = h / 2;
    func(x, y, next_h);
    func(x + next_h, y - next_h, next_h);
    func(x + next_h, y + next_h, next_h);
}   

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < MX; i++) {
        for (int j = 0; j < MY; j++) {
            board[i][j] = ' ';
        }
    }

    func(0, N - 1, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}