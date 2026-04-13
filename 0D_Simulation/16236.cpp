#include <bits/stdc++.h>
using namespace std;

int N;
pair<int,int> babyShark_loc;
int babyShark_size = 2;
int babyShark_food = 0;
int board[21][21];
int visited[21][21];

vector<pair<int,int>> candidates;
int min_dist;

pair<int,int> dir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
queue<pair<int,int>> Q;

int t = 0;

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void EatFish(pair<int,int> cur) {
    // cout << "eat fish at (" << cur.first << "," << cur.second << ") taking in " << visited[cur.first][cur.second] << "\n";
    babyShark_loc = cur;
    board[cur.first][cur.second] = 0;
    babyShark_food++;
    // printBoard();
    if (babyShark_food == babyShark_size) {
        babyShark_size++;
        babyShark_food = 0;
        // cout << "baby shark size up!: " << babyShark_size << '\n';
    }
    t += visited[cur.first][cur.second];
    return;
}

// 가장 가까운 물고기를 찾아서 이동하기. 없다면 false 반환.
bool BFS() {
    // cout << "baby shark starts finding fish at (" << babyShark_loc.first << "," << babyShark_loc.second <<")\n";
    for (int i = 0; i < 21; i++) {
        fill(visited[i], visited[i] + 21, -1);
    }

    Q.push(babyShark_loc);
    visited[babyShark_loc.first][babyShark_loc.second] = 0;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        if (candidates.size() > 0 && min_dist < visited[cur.first][cur.second]) {
            break;
        }

        if (board[cur.first][cur.second] > 0 && board[cur.first][cur.second] < babyShark_size) {
            if (!candidates.size()) min_dist = visited[cur.first][cur.second];
            candidates.push_back(cur);
        }

        for (pair<int,int> d : dir) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
            if (visited[dx][dy] >= 0)   continue;
            if (board[dx][dy] > babyShark_size) continue;
            Q.push({dx, dy});
            visited[dx][dy] = visited[cur.first][cur.second] + 1;
        }
    }

    if (!candidates.size()) return false;
    
    sort(candidates.begin(), candidates.end());
    EatFish(candidates[0]);
    while(!candidates.empty())  candidates.pop_back();
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] = 0;
                babyShark_loc = {i, j};
            }
        }
    }

    while (true) {
        bool res = BFS();
        if (!res)   break;
        while(!Q.empty())   Q.pop();
    }

    cout << t;
}