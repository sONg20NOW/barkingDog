#include <bits/stdc++.h>
using namespace std;

int N;
int board[17][17];

struct Pipe {
    int x, y;
    int dir;    // 가로: 0, 세로: 1, 대각선: 2
};

queue<Pipe> Q;
int method_cnt;

void func() {
    Q.push({0, 1, 0});
    while (!Q.empty()) {
        Pipe cur = Q.front();    Q.pop();
        if (cur.x == N-1 && cur.y == N-1) {
            method_cnt++;
            continue;
        }
        switch (cur.dir)
        {
        case 0:
            if (cur.y + 1 < N && !board[cur.x][cur.y + 1]) {
                Q.push({cur.x, cur.y + 1, 0});
                if (cur.x + 1 < N && !board[cur.x + 1][cur.y] && !board[cur.x + 1][cur.y + 1])  
                    Q.push({cur.x + 1, cur.y + 1, 2});
            } 
            break;
        case 1:
            if (cur.x + 1 < N && !board[cur.x + 1][cur.y]) {
                Q.push({cur.x + 1, cur.y, 1});
                if (cur.y + 1 < N && !board[cur.x][cur.y + 1] && !board[cur.x + 1][cur.y + 1])  
                    Q.push({cur.x + 1, cur.y + 1, 2});
            } 
            break;
        case 2:
            if (cur.y + 1 < N && !board[cur.x][cur.y+1]) 
                Q.push({cur.x, cur.y + 1, 0});
            if (cur.x + 1 < N && !board[cur.x+1][cur.y])
                Q.push({cur.x + 1, cur.y, 1});
            if (cur.y + 1 < N && !board[cur.x][cur.y+1]
            && cur.x + 1 < N && !board[cur.x+1][cur.y]
            && !board[cur.x+1][cur.y+1])
                Q.push({cur.x+1, cur.y+1, 2});
            break;
        
        default:
            break;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    func();

    cout << method_cnt;
}