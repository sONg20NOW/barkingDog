#include <bits/stdc++.h>
using namespace std;

int N;
int play_res[51][10];

int arr[9];
int visited[10];
int arr_idx = 0;

int runners = 0;

int max_score = -5;

int RunRunners(int h) {
    int score = 0;

    int temp = h;
    runners = runners + (1 << 3);
    while(temp--) {
        if (runners % 2 == 1) score++;
        runners = runners >> 1;
    }

    return score;
}

// arr 배열을 이용해서 게임 진행하기.
void PlayBall() {
    int ining = 0;
    int out_cnt = 0;
    int score = 0;
    while (ining < N) {
        int cur_player = arr[arr_idx] - 1;
        int play = play_res[ining][cur_player];
        arr_idx = (arr_idx + 1) % 9;
        if (play == 0) {
            out_cnt++;
        } else {
            score += RunRunners(play);
        }

        if (out_cnt >= 3) {
            ining++;
            out_cnt = 0;
            runners = 0;
        }
    }

    max_score = max(max_score, score);
}


// 1~9번까지 순서 정하기
void func(int k) {
    if (k == 9) {
        runners = 0;
        arr_idx = 0;
        PlayBall();
        
        return;
    }

    if (k == 3) {
        func(k + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (visited[i]) continue;
        arr[k] = i;
        visited[i] = 1;
        func(k + 1);
        visited[i] = 0;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> play_res[i][j];
        }
    }

    arr[3] = 1;
    visited[1] = 1;
    func(0);

    cout << max_score << '\n';
}