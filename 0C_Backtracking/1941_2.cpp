#include <bits/stdc++.h>
using namespace std;

// 보드에서 7개 고르는 백트래킹 -> BFS로 이어지는지 여부 확인 & S의 개수가 4 이상인지 확인

pair<int,int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

string board[5];
int vis[5][5];
int member[7];

int answer = 0;

bool BFS() {
    int bd[5][5];
    int cnt = 0;
    int S_cnt = 0;

    for (int i = 0; i < 5; i++) fill(bd[i], bd[i] + 5, 0);
    for (int m: member) {
        bd[m / 5][m % 5] = 1;
    }
    queue<int> Q;
    bd[member[0] / 5][member[0] % 5] = 2;
    Q.push(member[0]);

    while(!Q.empty()) {
        int cur = Q.front();  Q.pop();
        cnt++;
        if (board[cur / 5][cur % 5] == 'S')    S_cnt++;
        for (pair<int,int> d : dir) {
            int dx = d.first + cur / 5;
            int dy = d.second + cur % 5;
            if (dx < 0 || dy < 0 || dx >= 5 || dy >= 5) continue;
            if (bd[dx][dy] == 0 || bd[dx][dy] == 2) continue;
            bd[dx][dy] = 2;
            Q.push(dx * 5 + dy);
        }
    }

    if (cnt == 7 && S_cnt >= 4)   return true;
    return false;
}

// 칠공주 중 k번쨰 인원을 뽑는 함수
void func(int k) {
    if (k == 7) {
        // BFS 진행, S 수 체크
        if (BFS())    answer++;
        return;
    }

    int last_m = k == 0 ? -1 : member[k-1];
    for (int i = last_m + 1; i < 25; i++) { 
        member[k] = i;
        func(k + 1);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> board[i];
    }

    func(0);

    cout << answer;

}