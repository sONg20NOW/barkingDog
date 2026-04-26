#include <bits/stdc++.h>
using namespace std;

int N, M, K;

struct FireBall {
    int m, s, d;
};

// zero-index
queue<FireBall> board[51][51];
queue<FireBall> temp_board[51][51];

const pair<int,int> dir[8] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};

// board[i][j]에 있는 모든 파이어 볼 이동시키기
void moveFireBall(int i, int j) {
    queue<FireBall> fireballs = board[i][j];
    while (!board[i][j].empty()) {
        FireBall cur = board[i][j].front(); board[i][j].pop();

        int dx = i + dir[cur.d].first * cur.s;
        int dy = j + dir[cur.d].second * cur.s;

        while (dx < 0) {
            dx = (dx + N) % N;
        }
        if (dx >= N) {
            dx %= N;
        }

        while (dy < 0) {
            dy = (dy + N) % N;
        }
        if (dy >= N) {
            dy %= N;
        }

        temp_board[dx][dy].push(cur);
    }
}

// temp_board에 있는 파이어볼 합치기
void unionFireBalls() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int fb_cnt = temp_board[i][j].size();
            // 두 개 이상이면 합치기
            if (fb_cnt > 1) {
                int sum_m = 0;
                int sum_s = 0;
                // 모두 홀수: 1, 모두 짝수: 0, 그렇지않으면: 2
                int d_odd = -1;
                while (!temp_board[i][j].empty()) {
                    FireBall fb = temp_board[i][j].front();    temp_board[i][j].pop();
                    sum_m += fb.m;
                    sum_s += fb.s;
                    if (d_odd == 2) continue;
                    if (d_odd < 0) {
                        d_odd = fb.d % 2;
                    }
                    else if ((fb.d % 2 == 0 && d_odd == 1)
                || (fb.d % 2 == 1 && d_odd == 0)) {
                        d_odd = 2;
                    } 
                }

                sum_m /= 5;
                sum_s /= fb_cnt;

                if (sum_m > 0) {
                    int start_d = 0;
                    if (d_odd == 2) {
                        start_d = 1;
                    }
                    for (int p = 0; p < 4; p++) {
                        board[i][j].push({sum_m, sum_s, start_d + p * 2});
                    }
                }
            } else {
                while(!temp_board[i][j].empty()) {
                    FireBall fb = temp_board[i][j].front(); temp_board[i][j].pop();
                    board[i][j].push(fb);
                }
            }
        }
    }
}

// 남아있는 파이어볼 질량의 합 구하기
int sumFireballMass() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            while (!board[i][j].empty()) {
                FireBall cur = board[i][j].front(); board[i][j].pop();
                sum += cur.m;
            }
        }
    }

    return sum;
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;

        board[r-1][c-1].push({m, s, d});
    }

    while (K--) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j].size() > 0) {
                    moveFireBall(i, j);
                }
            }
        }
        unionFireBalls();
    }

    cout << sumFireballMass();
}