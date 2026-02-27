#include <bits/stdc++.h>
using namespace std;

struct xy_cnt {
    int x, y, cnt;
};

int board[200][200];
int dis[200][200][31];

pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
pair<int,int> horse_dir[8] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int main() {
    int K, W, H;
    cin >> K;

    cin >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }

    queue<xy_cnt> Q;
    dis[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()) {
        xy_cnt cur = Q.front(); Q.pop();
        if (cur.x == H - 1 && cur.y == W - 1) {
            cout << dis[cur.x][cur.y][cur.cnt] -1  << '\n';
            return 0;
        }
        // 말 이동으로 가는 BFS
        for (pair<int,int> d : horse_dir) {
            int dx = d.first + cur.x;
            int dy = d.second + cur.y;
            if (dx < 0 || dy < 0 || dx >= H || dy >= W) continue;
            if (dis[dx][dy][cur.cnt + 1] || cur.cnt + 1 > K || board[dx][dy])   continue;
            dis[dx][dy][cur.cnt + 1] = dis[cur.x][cur.y][cur.cnt] + 1;
            Q.push({dx,dy,cur.cnt+1});
        }
        // 일반적인 이동으로 가는 BFS
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.x;
            int dy = d.second + cur.y;
            if (dx < 0 || dy < 0 || dx >= H || dy >= W) continue;
            if (dis[dx][dy][cur.cnt] || board[dx][dy])   continue;
            dis[dx][dy][cur.cnt] = dis[cur.x][cur.y][cur.cnt] + 1;
            Q.push({dx,dy,cur.cnt});
        }

    }

    cout << -1 << '\n';
    return 0;
}