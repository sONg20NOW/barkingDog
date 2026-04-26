// 제미나이가 말한대로 풀어보기.
// 보드는 그대로, 구슬 위치만 바꾸면 된다.

#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MX = 11;
char board[MX][MX];
struct State {
    int rx, ry, bx, by, count;
};
// 초기 공 위치
int rx, ry, bx, by;
// 구멍 위치
int hx, hy;

queue<State> Q;
int visited[MX][MX][MX][MX];

pair<int,int> d[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

// 해당 공 위치에서 dir 방향으로 공을 굴려서 공 위치를 업데이트하는 함수
State tilt(State prev, int dir) {
    State next = prev;

    pair<int,int> flow = d[dir];
    while(board[next.rx + flow.first][next.ry + flow.second] != '#' && board[next.rx][next.ry] != 'O') {
        next.rx += flow.first;
        next.ry += flow.second;
    }
    while(board[next.bx + flow.first][next.by + flow.second] != '#' && board[next.bx][next.by] != 'O') {
        next.bx += flow.first;
        next.by += flow.second;
    }
    // 공이 구멍이 아닌 같은 위치에서 멈췄다면
    if (next.rx == next.bx && next.by == next.ry && !(next.rx == hx  && next.ry == hy)) {
        switch (dir)
        {
        case 0:
            if (prev.ry < prev.by) {
                next.by++;
            } else {
                next.ry++;
            }
            break;
        case 1:
             if (prev.ry < prev.by) {
                next.ry--;
            } else {
                next.by--;
            }
            break;
        case 2:
            if (prev.rx < prev.bx) {
                next.rx--;
            } else {
                next.bx--;
            }            
            break;
        case 3:
            if (prev.rx < prev.bx) {
                next.bx++;
            } else {
                next.rx++;
            }       
            break;
        default:
            break;
        }
    }

    next.count++;
    return next;
}

int main() {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'R') {
                rx = i; ry = j;
            } else if (board[i][j] == 'B') {
                bx = i; by = j;
            } else if (board[i][j] == 'O') {
                hx = i; hy = j;
            }
        }
    }
    
    Q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = 1;

    while(!Q.empty()) {
        State cur_state = Q.front();    Q.pop();

        for (int dir : {0, 1, 2, 3}) {
            State next = tilt(cur_state, dir);
            if (next.count > 10)    continue;
            if (next.bx == hx && next.by == hy)   continue;
            if (next.rx == hx && next.ry == hy) {
                cout << next.count << '\n';
                return 0;
            }
            if (visited[next.rx][next.ry][next.bx][next.by])    continue;
            Q.push(next);
            visited[next.rx][next.ry][next.bx][next.by] = 1;
        }
    }

    cout << -1 << '\n';
    return 0;
}