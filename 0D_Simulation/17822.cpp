#include <bits/stdc++.h>
using namespace std;

int N, M, T;
// r번째 원판의 적힌 수.
int board[51][51];
int x, d, k;

const pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

queue<pair<int,int>> Q;
queue<pair<int,int>> anotherQ;
int visited[51][51];

void printBoard() {
    cout << "===print board===\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }

        cout << '\n';
    }
}

void cleanQueue(queue<pair<int,int>>& queue) {
    while(!queue.empty()) {
        queue.pop();
    }
}

bool BFS(int i, int j) {
    bool flag = false;
    Q.push({i, j});
    visited[i][j] = 1;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        anotherQ.push(cur);
        for (pair<int,int> p : dir) {
            int dx = cur.first + p.first;
            int dy = cur.second + p.second;
            if (dx < 0 || dx >= N)  continue;
            if (dy < 0)         dy = M -1;
            else if (dy >= M)   dy = 0;
            if (visited[dx][dy] || board[dx][dy] != board[cur.first][cur.second])   continue;
            Q.push({dx, dy});
            visited[dx][dy] = 1;
        }
    }

    if (anotherQ.size() > 1) {
        flag = true;
        while (!anotherQ.empty()) {
            pair<int,int> cur = anotherQ.front();   anotherQ.pop();
            board[cur.first][cur.second] = 0;
        }
    }

    cleanQueue(anotherQ);
    return flag;
}

// 하나라도 처리된 경우가 있으면 true 반환.
bool DoTask() {
    bool flag = false;
    while(!Q.empty())   Q.pop();
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + M, 0);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] || board[i][j] == 0)  continue;
            bool res = BFS(i, j);
            if (res)    flag = true;
        }
    }

    return flag;
}

int SumBoard() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += board[i][j];
        }
    }

    return sum;
}

void DoTaskB() {
    int sum = 0;
    int cnt = 0;
    // 원판에 적힌 수의 평균 구하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] > 0) {
                sum += board[i][j];
                cnt++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] > 0) {
                // 평균보다 작다면 1 더하기
                if (board[i][j] * cnt < sum) {
                    board[i][j] += 1;
                } else if (board[i][j] * cnt > sum) {
                    board[i][j] -= 1;
                }
            }
        }
    }
}

// 원판에 수가 남아있으면, 
// 인접한 같은 수 찾고 인접한 수가 있으면 지우고 (지우는 건 0으로 처리), 
// 인접한 같은 수가 없으면 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에는 -1, 작은 수에는 +1.
void task() {
    int beforeSum = SumBoard();

    if (beforeSum == 0)   return;
    bool res = DoTask();

    if (!res) {
        DoTaskB();
    }
}

// r번 원판을 dir 방향으로 cnt만큼 회전시키는 함수
// dir => 0: 시계 / 1: 반시계
void Rotate(int r, int dir, int cnt) {
    // 시계 방향 회전부터 구현.
    while(cnt--) {
        if (dir == 0) {
            int temp = board[r][M-1];
            for (int c = M-1; c >= 1; c--) {
                board[r][c] = board[r][c-1];
            }
            board[r][0] = temp;
        } else {
            int temp = board[r][0];
            for (int c = 0; c < M-1; c++) {
                board[r][c] = board[r][c+1];
            }
            board[r][M-1] = temp;
        }
    }

}

void func() {
    for (int r = x; r <= N; r += x) {
        Rotate(r-1, d, k);
    }
    // printBoard();
    task();
    // printBoard();
}

int main() {
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    while(T--) {
        cin >> x >> d >> k;
        func();
        
    }


    cout << SumBoard() << '\n';
}