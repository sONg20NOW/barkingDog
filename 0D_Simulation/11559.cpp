#include <bits/stdc++.h>
using namespace std;

const int N = 12, M = 6;
char board[N][M];
int vis[N][M];
pair<int,int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<pair<int,int>> Q;
stack<pair<int,int>> history;

char temp[12];

void printBoard() {
    cout << "-----" << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

// 뿌요 밀기.
void gravity() {

    for (int j = 0; j <= M; j++) {
        fill(temp, temp + 12, '.');
        int idx = N - 1;
        for (int i = N - 1; i >= 0; i--) {
            if (board[i][j] != '.') temp[idx--] = board[i][j];
        }
        for (int i = N - 1; i >= 0; i--) {
            board[i][j] = temp[i];
        }
    }
}

// 연쇄가 있는 걸 파악하고 사라진 블럭을 .으로 바꾸기
// 연쇄로 없어진 블럭들이 있다면 true 반환
bool puyo() {
    bool isPuyo = false;

    for (int i = 0; i < N; i++) {
        fill(vis[i], vis[i] + M, 0);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '.') continue;
            if (vis[i][j] > 0)  continue;
            // BFS 시작
            char c = board[i][j];
            int cnt = 0;

            Q.push({i, j});
            vis[i][j] = 1;
            cnt++;
            while(!Q.empty()) {
                pair<int,int> cur = Q.front();  Q.pop();
                history.push(cur);
                for (pair<int,int> d : dir) {
                    int dx = d.first + cur.first;
                    int dy = d.second + cur.second;
                    if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
                    if (vis[dx][dy] > 0 || board[dx][dy] != c)    continue;
                    Q.push({dx, dy});
                    vis[dx][dy] = 1;
                    cnt++;
                }
            }

            if (cnt >= 4) {
                isPuyo = true;
                while (!history.empty()) {
                    pair<int,int> cur = history.top();    history.pop();
                    board[cur.first][cur.second] = '.';
                }
            }
            while(!history.empty()) history.pop();
        }
    }

    return isPuyo;
}

int main() {
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int count = 0;
    while (true) {
        bool isPuyo = puyo();
        if (!isPuyo) {
            break;
        } else {
            count++;
            gravity();
        }
    }
    // printBoard();
    cout << count << '\n';
}