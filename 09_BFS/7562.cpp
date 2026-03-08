#include <bits/stdc++.h>
using namespace std;
const int MX = 300;
int dis[MX][MX];
pair<int,int> dir[8] = {
    {-2, -1}, {-1, -2},
    {2, 1}, {1, 2},
    {-2, 1}, {-1, 2},
    {2, -1}, {1, -2}
};

int main(){
    int T;
    cin >> T;

    queue<pair<int,int>> Q;
    while(T--) {
        for (int i = 0; i < MX; i++) {
            fill(dis[i], dis[i] + MX, -1);
        }

        int l;
        cin >> l;

        int x, y;
        cin >> x >> y;
        Q.push({x,y});
        dis[x][y] = 0;

        cin >> x >> y;

        while(!Q.empty()) {
            pair<int,int> cur = Q.front();  Q.pop();
            if (cur.first == x && cur.second == y) {
                cout << dis[cur.first][cur.second] << '\n';
                while(!Q.empty())   Q.pop();
                break;
            }
            for (pair<int,int> d : dir) {
                int dx = d.first + cur.first;
                int dy = d.second + cur.second;
                if (dx < 0 || dy < 0 || dx >= l || dy >= l) continue;
                if (dis[dx][dy] != -1)  continue;
                dis[dx][dy] = dis[cur.first][cur.second] + 1;
                Q.push({dx,dy});
            }
        }
    }
}