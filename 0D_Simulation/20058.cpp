#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, Q, n;
const int MX = (1 << 6) + 1;
int board[MX][MX];
int temp_board[MX][MX];

const pair<int,int> dirs[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void printBoard() {
    cout << "=== print board ===\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

// (i,j)를 시작점으로 하는 격자를 L 단계만큼 시계방향으로 90도 회전시키는 함수
void rotateSmall(int i, int j, int L) {
    int l = (1 << L);
    
    for (int dx = 0; dx < l; dx++) {
        for (int dy = 0; dy < l; dy++) {
            temp_board[i + dx][j + dy] = board[i + (l-1 - dy)][j + dx];
        }
    }

    // temp_board -> board
    for (int dx = 0; dx < l; dx++) {
        for (int dy = 0; dy < l; dy++) {
            board[i + dx][j + dy] = temp_board[i + dx][j + dy];
        }
    }
}

// L이 주어질 때 회전시키는 함수
void rotateAll(int L) {
    int l = (1 << L);
    for (int i = 0; i < n / l; i++) {
        for (int j = 0; j < n / l; j++) {
            int x = i*l;
            int y = j*l;
            rotateSmall(x, y, L);
        }
    }
}

// 현재 보드에서 얼음이 있는 칸 3개 이상과 인접해있지 않으면 얼음 양을 1 줄이는 함수
void meltIce() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0)   continue;
            int ice = 0;
            for (pair<int,int> d: dirs) {
                int dx = d.first + i;
                int dy = d.second + j;
                if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
                if (board[dx][dy] == 0) continue;
                ice++;
            }
            temp_board[i][j] = (ice < 3 ? board[i][j] - 1 : board[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}

// 동작 함수
void func(int L) {
    rotateAll(L);
    meltIce();
}

int visited[MX][MX];

// BFS를 통해서 남아있는 얼음의 합과 가장 큰 덩어리가 차지하는 칸의 개수 출력
pair<int,int> solution() {
    int ice_cnt = 0;
    int max_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] || board[i][j] == 0)  continue;
            int sz = 0;
            queue<pair<int,int>> Q;
            Q.push({i, j});
            visited[i][j] = 1;

            while (!Q.empty()) {
                pair<int,int> cur = Q.front();  Q.pop();
                sz++;
                ice_cnt += board[cur.first][cur.second];
                for (pair<int,int> d : dirs) {
                    int dx = d.first + cur.first;
                    int dy = d.second + cur.second;
                    if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
                    if (visited[dx][dy] || !board[dx][dy])  continue;
                    Q.push({dx,dy});
                    visited[dx][dy] = 1;
                }
            }

            max_size = max(max_size, sz);
        }
    }

    return {ice_cnt, max_size};
}

int main() {
    cin >> N >> Q;
    n = (1 << N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while (Q--) {
        int L;
        cin >> L;
        func(L);
    }

    pair<int,int> ans = solution();

    cout << ans.first << '\n' << ans.second << '\n';
}