#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[9][9];

pair<int,int> virus_coor[10];
int v;

int arr[3];
int init_safe_area;
int max_safe_area;

pair<int,int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// virus 시작점들로부터 BFS 진행. 이후 침범한 0의 개수 반환.
int BFS() {
    queue<pair<int,int>> Q;
    int visited[N][M];
    for (int i = 0; i < N; i++) fill(visited[i], visited[i] + M, 0);

    // 시작점 넣기
    for (int i = 0; i < v; i++) {
        pair<int,int> v_coor = virus_coor[i];
        Q.push(v_coor);
        visited[v_coor.first][v_coor.second] = 1;
    }

    int infected = 0;

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if (visited[dx][dy] || board[dx][dy] != 0)    continue;
            visited[dx][dy] = 1;
            Q.push({dx, dy});
            infected++;
        }
    }

    return infected;
}

pair<int,int> intToCoor(int p) {
    int x = p / M;
    int y = p % M;
    return {x, y};
}

void func(int k) {
    if (k == 3) {
        int infected = BFS();
        max_safe_area = max(max_safe_area, init_safe_area - 3 - infected);

        return;
    }
    
    for (int i = (k == 0 ? 0 : arr[k - 1] + 1); i < N * M; i++) {
        pair<int,int> coor = intToCoor(i);
        if (board[coor.first][coor.second] != 0)    continue;
        arr[k] = i;
        board[coor.first][coor.second] = 1;
        func(k + 1);
        board[coor.first][coor.second] = 0;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) 
                virus_coor[v++] = {i, j};
            else if (board[i][j] == 0)
                init_safe_area++;
        }
    }

    func(0);

    cout << max_safe_area;
}