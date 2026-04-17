#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[51][51];
int temp_board[51][51];
int visited[51][51];
pair<int,int> candidates[10];
int cand_cnt;
int arr[10];
queue<pair<int,int>> Q;

pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

const int MX_T = 1 << 12;
int min_t = MX_T;

bool isClear() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp_board[i][j] == 0)   return false;
        }
    }

    return true;
}


void BFS() {
    int t = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp_board[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + N, -1);
    }
    while (!Q.empty())  Q.pop();

    for (int i = 0; i < cand_cnt; i++) {
        if (arr[i]) {
            pair<int,int> seed = candidates[i];
            Q.push(seed);
            visited[seed.first][seed.second] = 0;
        }
    }

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        if (temp_board[cur.first][cur.second] == 0)
            t = visited[cur.first][cur.second];
        temp_board[cur.first][cur.second] = 3;
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
            if (visited[dx][dy] >= 0) continue;
            if (temp_board[dx][dy] != 0 && temp_board[dx][dy] != 2) continue;
            Q.push({dx, dy});
            visited[dx][dy] = visited[cur.first][cur.second] + 1;
        }
    }

    if (isClear())    min_t = min(t, min_t);
}

// cand_cnt 중에 M개 고르기
void func(int k, int last_idx = -1) {

    if (k == M) {
        BFS();
        return;
    }

    for (int i = last_idx + 1; i < cand_cnt; i++) {
        arr[i] = 1;
        func(k + 1, i);
        arr[i] = 0;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                candidates[cand_cnt++] = {i, j};
            }
        }
    }

    func(0);

    cout << (min_t == (MX_T) ? -1 : min_t);
}