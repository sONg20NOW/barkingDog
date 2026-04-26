#include <bits/stdc++.h>
using namespace std;

// 메인 아이디어: 이동 후 바로 냄새를 남기는데, 냄새는 (남긴시간, 상어번호)로 저장
// 남긴시간이 현재 시간과 같으면 이동 가능 (그 상어도 지금 왔다는 거니까)
// 주의: 상어가 보고 있는 방향으로 가는 것이 아님!!

int N, M, K;

struct Cell {
    int shark_no, left_t;
};

// 상어의 냄새를 보관하는 보드 (first: 상어번호, second: 남긴시간)
Cell board[21][21];


// r과 c가 -1이면 게임에서 제외됐음을 의미
struct Shark {
    int r, c, dir;
};

// 각 상어가 다음에 이동할 좌표와 방향을 저장하는 배열
Shark next_coor[401];

// 각 상어의 번호가 인덱스로, 각 상어의 위치와 바라보는 방향을 저장.
Shark sharks[401];

// 가능한 방향 후보군 1: 상, 2: 하, 3: 좌, 4: 우
const pair<int,int> dirs[5] = {{}, {-1,0}, {1,0}, {0,-1}, {0,1}};

// 각 상어별 이동 우선순위를 저장
int shark_priority[401][5][4];

int out_cnt;
int t;

void printSharks() {
    cout << " === print shark at " << t <<  "===\n";
    string as[5] = {"", "up", "down", "left", "right"};
    for (int i = 1; i <= M; i++) {
        cout << i << "th shark: (" << sharks[i].r << "," << sharks[i].c << ") - dir: " << (as[sharks[i].dir]) << '\n';
    }
}

// i번 상어를 이동 예약 시키기.
void reserveMoveShark(int i) {
    if (sharks[i].r == -1 && sharks[i].c == -1) {
        return;
    }

    int prior[4];
    for (int p = 0; p < 4; p++) {
        prior[p] = shark_priority[i][sharks[i].dir][p];
    }

    // 인접한 칸 중 냄새가 없는 칸 찾아서 이동하기 (우선순위에 따라서)
    for (int d : prior) {
        int dx = sharks[i].r + dirs[d].first;
        int dy = sharks[i].c + dirs[d].second;
        if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
        // 해당 칸에 냄새가 남아있으면 이동 불가.
        if (board[dx][dy].shark_no != 0 && t - board[dx][dy].left_t <= K)    continue;
        // 이동할 수 있으므로 이동 예약.
        next_coor[i] = {dx, dy, d};
        return;
    }

    // 빈 칸이 없으면 내 냄새가 있던 곳으로 되돌아가기 
    for (int d : prior) {
        int dx = sharks[i].r + dirs[d].first;
        int dy = sharks[i].c + dirs[d].second;
        if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
        if (board[dx][dy].shark_no != i)    continue;
        // 이동할 수 있으므로 이동 예약.
        next_coor[i] = {dx, dy, d};

        return;
    }
}

// next_coor에 저장된 좌표로 상어 이동시키기
// 이 때, 같은 칸에 다른 상어가 있다면 비교 후 배제도 시행
void actualMoveShark(int i) {
    if (sharks[i].r == -1 && sharks[i].c == -1) {
        return;
    }

    int dx = next_coor[i].r;
    int dy = next_coor[i].c;
    // 만약 그 칸에 이미 다른 상어가 있다면 게임에서 배제
    if (board[dx][dy].shark_no != i
    && t - board[dx][dy].left_t == 0) {
        sharks[i].r = -1;
        sharks[i].c = -1;
        out_cnt++;
        return;
    }

    // 이동하고 냄새 남기기
    sharks[i] = next_coor[i];
    board[dx][dy] = {i, t};
}

// 1번부터 M번 상어 모두 움직이기
void MoveAllSharks() {
    for (int i = 1; i <= M; i++) {
        reserveMoveShark(i);
    }

    for (int i = 1; i <= M; i++) {
        actualMoveShark(i);
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a > 0) {
                board[i][j] = {a, 0};
                sharks[a].r = i;
                sharks[a].c = j;
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> sharks[i].dir;
    }

    for (int i = 1; i <= M; i++) {
        for (int d = 1; d <= 4; d++) {
            for (int k = 0; k < 4; k++) {
                cin >> shark_priority[i][d][k];
            }
        }
    }

    while (++t <= 1000) {
        MoveAllSharks();
        if (out_cnt == M - 1) {
            break;
        }
    }

    cout << (t > 1000 ? -1 : t);
}