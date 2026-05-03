#include <bits/stdc++.h>
using namespace std;

int dices[7] = {0, 1, 2, 3, 4, 5, 6};
int dice_dir = 0;
const pair<int,int> dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int N, M, K;
int board[21][21];

int dice_x, dice_y;

int score;

bool OOB(int r, int c) {
    return (r < 0 || r >= N || c < 0 || c >= M);
}

queue<pair<int,int>> Q;
queue<pair<int,int>> another_Q;
int sc[21][21];

void printSC() {
    cout << "=== print sc ===\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << sc[i][j] << ' ';
        }
        cout << '\n';
    }
}

// (r,c)의 점수를 반환하는 함수
int BFS(int r, int c) {
    if (sc[r][c] > 0) {
        return sc[r][c];
    }

    int local_score = 0;

    Q.push({r, c});
    sc[r][c] = 1;
    while (!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        another_Q.push(cur);
        local_score++;
        for (pair<int,int> d: dirs) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (OOB(dx, dy))    continue;
            if (sc[dx][dy] || board[dx][dy] != board[cur.first][cur.second])    continue;
            sc[dx][dy] = 1;
            Q.push({dx, dy});
        }
    }
    
    while (!another_Q.empty()) {
        pair<int,int> cur = another_Q.front();  another_Q.pop();
        sc[cur.first][cur.second] = local_score;
    }

    return sc[r][c];
}

// dice_dir 방향으로 주사위 굴려서 주사위 상태 바꾸기
void rollDice() {
    int temp = dices[1];
    switch (dice_dir)
    {
    case 0:
        dices[1] = dices[4];
        dices[4] = dices[6];
        dices[6] = dices[3];
        dices[3] = temp;
        break;
    case 1:
        dices[1] = dices[2];
        dices[2] = dices[6];
        dices[6] = dices[5];
        dices[5] = temp;
        break;
    case 2:
        dices[1] = dices[3];
        dices[3] = dices[6];
        dices[6] = dices[4];
        dices[4] = temp;
        break;
    case 3:
        dices[1] = dices[5];
        dices[5] = dices[6];
        dices[6] = dices[2];
        dices[2] = temp;
        break;
    
    default:
        break;
    }
}

// 주사위를 이동방향으로 한 칸 굴리기 / 칸이 없으면 반대로
void func() {
    int dx = dirs[dice_dir].first + dice_x;
    int dy = dirs[dice_dir].second + dice_y;
    if (OOB(dx, dy)) {
        dice_dir = (dice_dir + 2) % 4;
        dx = dirs[dice_dir].first + dice_x;
        dy = dirs[dice_dir].second + dice_y;
    }

    rollDice();

    int A = dices[6];
    int B = board[dx][dy];
    int C = BFS(dx, dy);

    score += B * C;
    if (A > B)  dice_dir = (dice_dir + 1) % 4;
    else if (A < B) dice_dir = (dice_dir - 1 + 4) % 4;

    dice_x = dx;
    dice_y = dy;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    while (K--) {
        func();
    }

    cout << score;
}