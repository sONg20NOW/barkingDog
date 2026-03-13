#include <bits/stdc++.h>
using namespace std;

pair<int,int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

string board[5];
// BFS 진행에서 사용되는 vis 배열(들어가고 나갈 때 처리)
int vis[5][5];
// 특정 좌표로부터 시작되는 경우의 수를 파악하기 위한 배열
// 영구적으로 유지됨.
// 근데 그냥 vis 배열 쓰면 되지 않나?
int st_vis[5][5];
pair<int,int> path[7];
int Y_cnt;

int answer = 0;

// 칠공주 중 결성된 인원의 수
void func(int k) {
    if (Y_cnt >= 4) return;

    if (k == 6) {
        for (int i = 0; i < 7; i++) {
            cout << path[i].first << ',' << path[i].second << "->" << '\n';
        }
        cout << "answer! " << answer << " Y_cnt: " << Y_cnt << '\n';
        answer++;
        return;
    }


    for (int i = 0; i < k; i++) {
        pair<int,int> cur = path[i];
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (dx < 0 || dy < 0 || dx >= 5 || dy >= 5)  continue;
            if (vis[dx][dy])    continue;
            path[k] = {dx, dy};
            vis[dx][dy] = 1;
            if (board[dx][dy] == 'Y')   Y_cnt++;
            func(k + 1);
            if (board[dx][dy] == 'Y')   Y_cnt--;
            vis[dx][dy] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            path[0] = {i, j};
            vis[i][j] = 1;
            if (board[i][j] == 'Y') Y_cnt++;
            func(1);
            if (board[i][j] == 'Y') Y_cnt--;

        }
    }

    cout << answer;

}