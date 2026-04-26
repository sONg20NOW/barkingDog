#include <bits/stdc++.h>
using namespace std;

int N, M, D;
int board[16][16];
int temp_board[16][16];

int arr[16];
queue<pair<int,int>> dead_enemies;
queue<pair<int,int>> Q;
int visited[16][16];
vector<pair<int,int>> candidates;

pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int ans;

bool isGameEnd() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp_board[i][j] == 1)    return false;
        }
    }

    return true;
}

void printTempBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << temp_board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << " ---- \n";
}

void BFS(int i) {
    int min_dist = 0;

    // BFS 시작
    Q.push({N-1, i});
    visited[N-1][i] = 1;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        if (temp_board[cur.first][cur.second] == 1) {
            if (candidates.empty()) min_dist = visited[cur.first][cur.second];
            
            if (min_dist == visited[cur.first][cur.second]) candidates.push_back(cur);
            else    return;
        }
        for (pair<int,int> d: dir) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M)  continue;
            if (visited[dx][dy] >= 0)   continue;
            visited[dx][dy] = visited[cur.first][cur.second] + 1;
            if (visited[dx][dy] > D)    continue;
            Q.push({dx, dy});
        }
    }
}

bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

// i번째 위치에서 궁수가 사격.
void Fire(int i) {
    // Q 초기화, visited, candidates 초기화
    while (!Q.empty())  Q.pop();
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + M, -1);
    }
    while (!candidates.empty()) candidates.pop_back();

    BFS(i);

    sort(candidates.begin(), candidates.end(), compare);
    if(!candidates.empty())    dead_enemies.push(candidates[0]);
}

void playGame() {
    // board 복사
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp_board[i][j] = board[i][j];
        }
    }

    int kill = 0;
    int t = 0;
    while (!isGameEnd()) {
        // 궁수 공격
        for (int i = 0; i < M; i++) {
            if (arr[i]) Fire(i);
        }

        // 사망자 처리
        while (!dead_enemies.empty()) {
            pair<int,int> cur = dead_enemies.front();   dead_enemies.pop();
            if (temp_board[cur.first][cur.second]) {
                temp_board[cur.first][cur.second] = 0;
                kill++;
            }
        }
        
        // 적 진군
        for (int j = 0; j < M; j++) {
            for (int i = N-1; i > 0; i--) {
                temp_board[i][j] = temp_board[i-1][j];
            }
            temp_board[0][j] = 0;
        }

        // cout << "time: " << t++ << "/ kill: " <<kill<<"---\n";
        // printTempBoard();
    }


    ans = max(ans, kill);
}

void func(int k, int last_idx = -1) {
    if (k == 3) {
        playGame();
        return;
    }

    for (int i = last_idx + 1; i < M; i++) {
        arr[i] = 1;
        func(k + 1, i);
        arr[i] = 0;
    }
}

int main() {
    cin >> N >> M >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    func(0);
    cout << ans << '\n';
}