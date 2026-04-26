#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int board[51][51];
int t_board[51][51];

int r, c, s;

// 0: 좌 , 1: 하, 2: 우, 3: 상
pair<int,int> dir[4] = {{0,-1}, {1,0}, {0,1}, {-1,0}};

struct RCS {
    int r, c, s;
};

RCS cmds[7];
int min_sum = 50000;

void GetValue() {
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < M; j++) {
            sum += t_board[i][j];
        }
        min_sum = min(min_sum, sum);
    }
}

void PrintBoard() {
    cout << " === print board === \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Rotate(int r, int c, int s) {
    while(s) {

        int dx = r - s;
        int dy = c;
        int temp = t_board[dx][dy];
        // 0: 우 , 1: 상, 2: 좌, 3: 하
        int d = 0;
        do {
            int next_x = dx + dir[d].first;
            int next_y = dy + dir[d].second;
            if (next_x < r - s || next_y < c - s || next_x > r + s || next_y > c + s) {
                d = (d + 1) % 4;
                next_x = dx + dir[d].first;
                next_y = dy + dir[d].second;
            }
            t_board[dx][dy] = t_board[next_x][next_y];
            dx = next_x;
            dy = next_y;
            // cout << "dx and dy : "<< dx << ", " << dy << '\n';
        }
        while (dx != r - s || dy != c);
        t_board[dx][dy + 1] = temp;

        s--;
    }
}

void CopyTempBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            t_board[i][j] = board[i][j];
        }
    }
}

// 0~K-1까지 순서 정하기
int arr[7];
int visited[7];

void func(int k) {
    if (k == K) {
        CopyTempBoard();
        for (int i = 0; i < K; i++) {
            int idx = arr[i];
            RCS cur_cmd = cmds[idx];
            Rotate(cur_cmd.r, cur_cmd.c, cur_cmd.s);
        }
        GetValue();

        return;
    }

    for (int i = 0; i < K; i++) {
        if (visited[i]) continue;
        arr[k] = i;
        visited[i] = 1;
        func(k + 1);
        visited[i] = 0;
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> r >> c >> s;
        cmds[i] = {r-1, c-1, s};
    }

    func(0);

    cout << min_sum;
}