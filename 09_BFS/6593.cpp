#include <bits/stdc++.h>
using namespace std;
const int MX = 30;
string board[MX][MX];
int vis[MX][MX][MX];
struct XYZ {
    int z,x,y;
};

XYZ dir[6] = {
    {1,0,0}, {-1,0,0},
    {0,1,0}, {0,-1,0},
    {0,0,1}, {0,0,-1}
};


int main() {
    queue<XYZ> Q;

    while(true) {
        int L, R, C;
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> board[i][j];
                for (int k = 0; k < C; k++) {
                    if (board[i][j][k] == 'S') {
                        Q.push({i, j, k});
                        vis[i][j][k] = 1;
                    }
                }
            }
        }

        bool imps = true;
        // BFS 진행
        while(!Q.empty()) {
            XYZ cur = Q.front();    Q.pop();
            if (board[cur.z][cur.x][cur.y] == 'E') {
                cout << "Escaped in " << vis[cur.z][cur.x][cur.y] - 1 << " minute(s)." << '\n';
                while(!Q.empty())   Q.pop();
                imps = false;
                break;
            }
            for (XYZ d : dir) {
                int dz = d.z + cur.z;
                int dx = d.x + cur.x;
                int dy = d.y + cur.y;
                if (dx < 0 || dy < 0 || dz < 0) continue;
                if (dz >= L || dx >= R || dy >= C)  continue;
                if (vis[dz][dx][dy] > 0 || board[dz][dx][dy] == '#')    continue;
                vis[dz][dx][dy] = vis[cur.z][cur.x][cur.y] + 1;
                Q.push({dz,dx,dy});
            }
        }

        if (imps)   cout << "Trapped!" << '\n';

        // vis 배열 초기화
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                fill(vis[i][j], vis[i][j] + MX, 0);
            }
        }
    }

}