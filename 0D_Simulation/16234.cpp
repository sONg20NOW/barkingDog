#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int board[51][51];

int visited[51][51];
queue<pair<int,int>> Q;
queue<pair<int,int>> anotherQ;

const pair<int,int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cnt;

void BFS() {
    int sum = 0;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        sum += board[cur.first][cur.second];
        anotherQ.push(cur);
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
            int diff = abs(board[cur.first][cur.second] - board[dx][dy]);
            if (visited[dx][dy] || diff < L || diff > R)    continue;
            visited[dx][dy] = cnt;
            Q.push({dx, dy});
        }
    }

    int each = sum / anotherQ.size();
    while(!anotherQ.empty()) {
        pair<int,int> cur = anotherQ.front();   anotherQ.pop();
        board[cur.first][cur.second] = each;
    }

    return;
}

bool func() {
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + N, 0);
    }

    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j])  continue;
            visited[i][j] = ++cnt;
            Q.push({i, j});
            BFS();
        }
    }

    if (cnt == N * N)   return false;
    return true;
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int day = 0;
    while(true) {
        bool res = func();
        if (!res)   break;
        day++;
    }

    cout << day;
}