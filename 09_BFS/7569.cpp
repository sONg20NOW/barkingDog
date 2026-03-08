#include <bits/stdc++.h>
using namespace std;
const int MX = 100;
int board[MX][MX][MX];
struct ZXY {
    int z, x, y;
};

ZXY dir[6] = {
    {0,0,1}, {0,0,-1},
    {0,1,0}, {0,-1,0},
    {1,0,0}, {-1,0,0}
};

bool ExistUngrown(int H, int N, int M) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (board[i][j][k] == 0) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int M, N, H;
    cin >> M >> N >> H;

    queue<ZXY> Q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    Q.push({i,j,k});
                }
            }
        }
    }

    int time = 0;
    // BFS 진행 후 익지 않은 토마토가 있다면 -1 출력
    while(!Q.empty()) {
        if (!ExistUngrown(H, N, M)) {
            cout << time << '\n';
            return 0;
        }
        int size = Q.size();
        while(size--) {
            ZXY cur = Q.front();    Q.pop();
            // cout << '{' << cur.z << ',' << cur.x << ',' << cur.y << '}' << '\n';
            for (ZXY d : dir) {
                int dz = d.z + cur.z;
                int dx = d.x + cur.x;
                int dy = d.y + cur.y;
                if (dz < 0 || dx < 0 || dy < 0) continue;
                if (dz >= H || dx >= N || dy >= M)  continue;
                if (board[dz][dx][dy] != 0) continue;
                board[dz][dx][dy] = 1;
                Q.push({dz,dx,dy});
            }
        }
        time++;
    }
    
    if (ExistUngrown(H, N, M)) {
        cout << -1 << '\n';
        return 0;
    }
}