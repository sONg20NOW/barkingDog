#include <bits/stdc++.h>
using namespace std;

pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

// 씨를 뿌릴 수 있는 좌표의 개수
int seed_cnt;

int N, M, G, R;
int board[50][50];
// 씨 뿌리는 게 가능한 구역의 좌표들
pair<int,int> seed[10];

int state[10]; // 0:무, 1:G, 2:R

int max_flower = 0;

// 배양액이 퍼지는 타임라인
int timestamp[50][50];
// 해당 위치에 뭐가 있는지에 대한 정보 (0: 아무것도 없음, 1: G, 2: R, 3: F)
int earth[50][50];

// R, G에 대해서 BFS 진행
// R과 G에 대해서 BFS 동시에 진행.
// 라운드 개념으로 R 1초 진행 - G 1초 진행
// 기록은 어떻게 해야지??
// 타임스탬프와 그 칸에 뭐가 있는지 두개의 배열 사용.
// R을 진행할 때
// G나 F가 아니고 진행할 수 있는 땅이라면 진행
// G가 진행할 때
// F를 만나면 중단.
// R을 만났을 때 같은 타임스탬프라면 꽃을 피우고 중단
// 아니라면 중단.
int BFS() {
    int f_cnt = 0;

    // 초기화
    for (int i = 0; i < N; i++) {
        fill(timestamp[i], timestamp[i] + M, 0);
        fill(earth[i], earth[i] + M, 0);
    }

    queue<pair<int,int>> Q;

    for (int i = 0; i < seed_cnt; i++){
        // G case
        if (state[i] == 1) {
            pair<int,int> s = seed[i];
            timestamp[s.first][s.second] = 0;
            earth[s.first][s.second] = 1;
            Q.push(s);
        } 
        // R case
        else if (state[i] == 2) {
            pair<int,int> s = seed[i];
            timestamp[s.first][s.second] = 0;
            earth[s.first][s.second] = 2;
            Q.push(s);
        }
    }

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();  Q.pop();
        if (earth[cur.first][cur.second] == 3) continue;    //Gemini
        for (pair<int,int> d : dir) {
            int dx = d.first + cur.first;
            int dy = d.second + cur.second;
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if (board[dx][dy] == 0) continue;
            // R의 경우
            if (earth[cur.first][cur.second] == 2) {
                if (earth[dx][dy] == 3 || earth[dx][dy] == 2) continue;
                if (earth[dx][dy] == 1) {
                    if (timestamp[dx][dy] == timestamp[cur.first][cur.second] + 1) {
                        earth[dx][dy] = 3;
                        f_cnt++;
                    } 
                    continue;
                }
                earth[dx][dy] = 2;
                timestamp[dx][dy] = timestamp[cur.first][cur.second] + 1;
                Q.push({dx, dy});
             } 
            // G의 경우
            else if (earth[cur.first][cur.second] == 1) {
                if (earth[dx][dy] == 3 || earth[dx][dy] == 1) continue;
                if (earth[dx][dy] == 2) {
                    if (timestamp[dx][dy] == timestamp[cur.first][cur.second] + 1) {
                        earth[dx][dy] = 3;
                        f_cnt++;
                    } 
                    continue;
                }
                earth[dx][dy] = 1;
                timestamp[dx][dy] = timestamp[cur.first][cur.second] + 1;
                Q.push({dx, dy});
            }
        }
    }

    return f_cnt;
}


void func(int idx, int g_cnt, int r_cnt) {
    if (idx == seed_cnt) {
        if (g_cnt == G && r_cnt == R) max_flower = max(max_flower, BFS());
        return;
    }
    // 초록색 뿌리기
    if (g_cnt < G) {
        state[idx] = 1;
        func(idx + 1, g_cnt + 1, r_cnt);
    }
    // 빨간색 뿌리기
    if (r_cnt < R) {
        state[idx] = 2;
        func(idx + 1, g_cnt, r_cnt + 1);
    }
    // 안 뿌리기
    state[idx] = 0;
    func(idx + 1, g_cnt, r_cnt);
}

void func2(int idx, int g_cnt, int r_cnt) {
    if (idx == seed_cnt) {
        if (g_cnt == G && r_cnt == R) 
            max_flower = max(max_flower, BFS());
        return;
    } 

    if (g_cnt < G) {
        state[idx] = 1;
        func2(idx + 1, g_cnt + 1, r_cnt);
    }
    if (r_cnt < R) {
        state[idx] = 2;
        func2(idx + 1, g_cnt, r_cnt + 1);
    }
    state[idx] = 0;
    func2(idx + 1, g_cnt, r_cnt);
} 

// void func(int g, int r) {
//     if (g == G && r == R) {
//         max_flower = max(max_flower, BFS());

//         return;
//     }

//     // G를 아직 다 안 뽑은 경우
//     if (g < G) {
//         int last_idx = g == 0 ? -1 : G_idx[g - 1];
//         for (int i = last_idx + 1; i < seed_cnt; i++) {
//             G_idx[g] = i;
//             func(g + 1, r);
//         }
//     } 
//     // G는 다 뽑은 경우, 남은 것 중에 G를 뽑기.
//     else {
//         int last_idx = r == 0 ? -1 : R_idx[r - 1];
//         for (int i = last_idx + 1; i < seed_cnt; i++) {
//             for (int g : G_idx) {
//                 if (g == i) continue;
//             }
//             R_idx[r] = i;
//             func(g, r + 1);
//         }
//     }
// }

int main() {
    cin >> N >> M >> G >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2)   seed[seed_cnt++] = {i, j};
        }
    }

    // 0 ~ seed_cnt 중 G개를 뽑고 나머지 중에 R개를 뽑는 문제.
    func2(0, 0, 0);
    cout << max_flower;

    return 0;
}