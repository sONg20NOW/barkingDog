#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, K, L;

// 0: 빈칸, 1: 사과, 2: 뱀
int board[101][101];
struct info {
    int when;
    char rotate_d;
};
info infos[101];

// 다음 정보로 넘어갈 때마다 ++;
int info_cnt = 0;

const pair<int,int> dirs[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int d;
deque<pair<int,int>> snake;

int t = 1;

// 정상 진행됐으면 true, 게임 오버 됐으면 false 반환.
bool func() {
    // 다음 칸으로 이동
    int dx = snake.front().first + dirs[d].first;
    int dy = snake.front().second + dirs[d].second;
    if (dx < 0 || dy < 0 || dx >= N || dy >= N || board[dx][dy] == 2) return false;
    if (board[dx][dy] != 1) {
        pair<int,int> tail = snake.back();  snake.pop_back();
        board[tail.first][tail.second] = 0;
    }
    
    board[dx][dy] = 2;
    snake.push_front({dx, dy});

    // 방향 전환?
    info cur_info = infos[info_cnt];
    if (cur_info.when == t) {
        if (cur_info.rotate_d == 'L') {
            d = (d - 1 + 4) % 4;
        } else {
            d = (d + 1) % 4;
        }
        info_cnt++;
    }

    return true;
}

int main() {
    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        r--;    c--;
        board[r][c] = 1;
    }
    cin >> L;
    for(int i = 0; i < L; i++) {
        int x;
        char c;
        cin >> x >> c;
        infos[i] = {x, c};
    }

    board[0][0] = 2;
    snake.push_back({0, 0});

    while (true) {
        bool res = func();
        if (!res)   break;

        t++;
    }

    cout << t;
}