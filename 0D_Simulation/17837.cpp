#include <bits/stdc++.h>
using namespace std;

int N, K;
// 0은 흰색, 1은 빨간색, 2는 파란색
// 추가적으로 보드는 0부터 시작.
int board[13][13];
deque<int> state[13][13];

const pair<int,int> directions[5] = {{}, {0,1}, {0,-1}, {-1,0}, {1,0}};

struct Horse {
    int r, c, dir;
    // dir=> 1: >, 2: <, 3: 상, 4: 하
};
Horse players[11];

// player_i번 말을 (dx,dy)로 이동시키는 함수 (그 위에 있는 말도)
// 빨간 칸일 경우 기존 순서를 다르게
bool movePlayer(int player_i, int dx, int dy) {
    bool red = board[dx][dy] == 1;

    int r = players[player_i].r;
    int c = players[player_i].c;

    deque<int> pack;
    while (pack.empty() || pack.front() != player_i) {
        pack.push_front(state[r][c].back()); state[r][c].pop_back();
    }

    while (!pack.empty()) {
        if (!red) {
            int cur_i = pack.front();
            state[dx][dy].push_back(cur_i);      pack.pop_front();
            players[cur_i] = {dx, dy, players[cur_i].dir};

        } else {
            int cur_i = pack.back();
            state[dx][dy].push_back(cur_i);       pack.pop_back();
            players[cur_i] = {dx, dy, players[cur_i].dir};
        }
    }

    if (state[dx][dy].size() >= 4)  return false;
    return true;
}

// 보드에서 벗어나거나 파란 칸인지 확인하는 함수
bool isBlock(int dx, int dy) {
    return (dx <= 0 || dy <= 0 || dx > N || dy > N || board[dx][dy] == 2);
}

// player_i의 다음 위치를 특정하는 함수
pair<int,int> nextLoc(int player_i) {
    Horse cur_p = players[player_i];

    int dx = directions[cur_p.dir].first + cur_p.r;
    int dy = directions[cur_p.dir].second + cur_p.c;
    return {dx, dy};
}

// 종료조건 만족 시 false 반환.
bool func() {
    // 0번 말부터 K-1번 말까지 진행
    for (int i = 0; i < K; i++) {
        pair<int,int> next_loc = nextLoc(i);
        int dx = next_loc.first;
        int dy = next_loc.second;
        // 다음 칸이 보드 밖이거나 파란 칸인 경우 방향을 바꾸고 반대로 한칸 이동
        // 그 칸도 벗어나거나 파란색이면 가만히..
        if (isBlock(dx, dy)) {
            // 방향 바꾸기 1 <-> 2, 3 <-> 4
            if (players[i].dir == 1 || players[i].dir == 3)   players[i].dir++;
            else    players[i].dir--;
            
            pair<int,int> next_loc = nextLoc(i);
            int dx = next_loc.first;
            int dy = next_loc.second;
            if (!isBlock(dx,dy)) {
                bool res = movePlayer(i, dx, dy);
                if (!res)   return false;
            }
        } else {
            bool res = movePlayer(i, dx, dy);
            if (!res)   return false;
        }
    }

    return true;
}


int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int r, c, dir;
        cin >> r >> c >> dir;
        players[i] = {r, c, dir};
        state[r][c].push_back(i);
    }

    int turn = 1;
    while (true) {
        bool res = func();
        if (!res || turn > 1000)   break;

        turn++;
    }

    cout << (turn > 1000 ? -1 : turn);
}