#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
long long fuel;

pair<int,int> taxi;
// 1-index
// 0: 빈칸, 1: 벽, 2+: 손님이 있는 자리
int board[22][22];

const pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

// 손님 번호 (2부터 시작)를 인덱스로 갖는 손님의 목적지 정보
pair<int,int> dst[2 + 441];

int remain_c;

bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.X == b.X) {
        return a.Y < b.Y;
    }
    return a.X < b.X;
}

// 현재 택시 위치에서부터 가장 가까운 손님 찾아서 이동하기
// 가장 가까운 승객이 여럿이라면 행번호가 가장 작은, 열 번호가 가장 작은 승객 태우기
// 손님을 태울 수 없으면 -1 반환, 손님을 태우면 그 손님의 번호 반환.
int findCustomer() {
    vector<pair<int,int>> candidates;
    queue<pair<int,int>> Q;

    int dist[22][22];
    for (int i = 1; i <= N; i++) {
        fill(dist[i] + 1, dist[i] + 1 + N, -1);
    }

    int min_dist = 4000;

    dist[taxi.X][taxi.Y] = 0;
    Q.push(taxi);
    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        // 현재 거리가 연료로 못 가는 거리라면, 혹은 이미 최단거리의 손님보다 멀어졌다면 종료
        if (dist[cur.X][cur.Y] > fuel || dist[cur.X][cur.Y] > min_dist)  break;
        // 현재 위치에 손님이 있다면 후보군에 넣기
        if (board[cur.X][cur.Y] >= 2) {
            candidates.push_back(cur);
            if (min_dist == 4000)   min_dist = dist[cur.X][cur.Y];
        }
        for (pair<int,int> d : dir) {
            int dx = d.X + cur.X;
            int dy = d.Y + cur.Y;
            if (dx <= 0 || dy <= 0 || dx > N || dy > N) continue;
            if (board[dx][dy] == 1 || dist[dx][dy] >= 0)    continue;
            dist[dx][dy] = dist[cur.X][cur.Y] + 1;
            Q.push({dx, dy});
        }
    }

    if (candidates.size() == 0) {
        return -1;
    }

    sort(candidates.begin(), candidates.end(), compare);

    // 연료차감/손님 태우기/택시 이동
    pair<int,int> target = candidates[0];
    fuel -= dist[target.X][target.Y];

    int temp = board[target.X][target.Y];
    board[target.X][target.Y] = 0;

    taxi = target;

    return temp;
}

// 승객 c의 목적지로 택시를 이동시키고 충전하는 함수
bool driveToDst(int c) {
    pair<int,int> loc = dst[c];

    queue<pair<int,int>> Q;

    int dist[22][22];
    for (int i = 1; i <= N; i++) {
        fill(dist[i] + 1, dist[i] + 1 + N, -1);
    }

    dist[taxi.X][taxi.Y] = 0;
    Q.push(taxi);

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        if (dist[cur.X][cur.Y] > fuel)  break;
        // 성공적으로 목적지에 도달하면 이동하면서 소모한 연료양의 두배를 충전.
        if (cur.X == loc.X && cur.Y == loc.Y) {
            fuel += dist[cur.X][cur.Y];
            taxi = cur;
            remain_c--;
            return true;
        }
        for (pair<int,int> d : dir) {
            int dx = d.X + cur.X;
            int dy = d.Y + cur.Y;
            if (dx <= 0 || dy <= 0 || dx > N || dy > N)     continue;
            if (board[dx][dy] == 1 || dist[dx][dy] >= 0)    continue;
            dist[dx][dy] = dist[cur.X][cur.Y] + 1;
            Q.push({dx, dy});
        }
    }

    return false;
}

int main() {
    cin >> N >> M >> fuel;
    remain_c = M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    cin >> taxi.X >> taxi.Y;

    for (int i = 0; i < M; i++) {
        int r, c, dr, dc;
        cin >> r >> c >> dr >> dc;
        board[r][c] = 2 + i;
        dst[2 + i] = {dr, dc};
    }

    while(remain_c > 0) {
        int next_customer = findCustomer();
        if (next_customer < 0) {
            cout << -1;
            return 0;
        }

        bool canArrive = driveToDst(next_customer);
        if (!canArrive) {
            cout << -1;
            return 0;
        }
    }

    cout << fuel;
}