#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const pair<int,int> dirs[9] = {{},
{0,-1}, {-1,-1}, {-1,0}, {-1,1},
{0,1}, {1,1}, {1,0}, {1,-1}};
const pair<int,int> adj_dirs[4] = {{-1,-1}, {-1,1}, {1,1}, {1,-1}};

// zero-index

// 구름의 이동 : queue로 해서 개별적으로 하면 될 것 같고,
// 구름이 생길 때 구름이 사라진 칸이 아니어야 한다는 어떻게 처리해야하지..
// => 이차원 배열에 구름의 최종 위치를 저장할까
int N, M;
int board[51][51];

// 구름이 생성된 위치를 저장하는 큐
queue<pair<int,int>> cloud_Q;

// 구름이 사라진 위치를 저장하는 이차원 배열
int vanished[51][51];

int d, s;

// 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수를 반환하는 함수
int adjWater(int r, int c) {
    int cnt = 0;
    for (pair<int,int> d : adj_dirs) {
        int dx = r + d.X;
        int dy = c + d.Y;
        if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
        if (board[dx][dy] > 0) cnt++;
    }

    return cnt;
}

// 물의 양의 합 구하는 함수
int sumWater() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += board[i][j];
        }
    }
    return ans;
}

// board 출력
void printBoard() {
    cout << "=== print board ===\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void func() {
    for (int i = 0; i < N; i++) {
        fill(vanished[i], vanished[i] + N, 0);
    }
    // 1. 모든 구름을 d 방향 s 칸 이동시키고 
    // 2. 비를 내려서 물 증가 시키고
    while(!cloud_Q.empty()) {
        pair<int,int> cur = cloud_Q.front();    cloud_Q.pop();
        int dx = cur.X + dirs[d].X * s;
        int dy = cur.Y + dirs[d].Y * s;
        while (dx < 0) {
            dx = (dx + N) % N;
        }
        while (dy < 0) {
            dy = (dy + N) % N;
        }

        if (dx >= N)    dx %= N;
        if (dy >= N)    dy %= N;

        board[dx][dy]++;
        vanished[dx][dy] = 1;
    }

    // 3. 물 증가한 칸에 대해서 물복사하고
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vanished[i][j]) 
                board[i][j] += adjWater(i, j);
        }
    }

    // 4. 구름이 사라지지 않은 칸에 대해 = 물 증가하지 않은 칸에 대해
    // 물이 2 이상이면 구름 생기게 하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vanished[i][j] && board[i][j] >= 2) {
                cloud_Q.push({i, j});
                board[i][j] -= 2;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cin >> board[i][j];
    }

    cloud_Q.push({N-1, 0});
    cloud_Q.push({N-1, 1});
    cloud_Q.push({N-2, 0});
    cloud_Q.push({N-2, 1});

    while (M--) {
        cin >> d >> s;
        func();
    }

    cout << sumWater();
}