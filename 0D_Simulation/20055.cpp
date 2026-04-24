#include <bits/stdc++.h>
using namespace std;

int N, K;
int dur[201];
int up_idx, down_idx;

int phase = 1;

// 메인 아이디어: 로봇은 항상 up_idx <= i < down_idx에 있다.

// 로봇이 i번째 칸에 있는지를 기록하는 배열
int isRobot[201];

void printDur() {
    cout << "--- print dur at " << phase << " ---\n";
    for (int i = 0; i < 2*N; i++) {
        cout << dur[i] << ' ';
    }
    cout << '\n';

    cout << "--- print robot at " << phase << " ---\n";
    for (int i = 0; i < 2*N; i++) {
        cout << isRobot[i] << ' ';
    }
    cout << '\n';
}

// 1번 과정을 실행하는 함수
void rotateBelt() {
    up_idx = (up_idx - 1 + 2 * N) % (2 * N);
    down_idx = (down_idx - 1 + 2 * N) % (2 * N);

    if (isRobot[down_idx]) {
        isRobot[down_idx] = 0;
    }
}

// 2번 과정을 실행하는 함수 (로봇 이동)
void moveRobots() { 
    for (int i = (down_idx - 1 + 2*N) % (2*N); i != (up_idx - 1 + 2 * N) % (2 * N); i = (i - 1 + 2*N) % (2*N)) {
        int next_i = (i + 1) % (2*N);
        if (isRobot[i] && !isRobot[next_i] && dur[next_i] > 0) {
            isRobot[next_i] = 1;
            isRobot[i] = 0;
            dur[next_i]--;

            if (next_i == down_idx) {
                isRobot[next_i] = 0;
            }
        }
    }
}

// 3번 과정을 실행하는 함수 (로봇 올리기)
void upRobot() {
    if (dur[up_idx] > 0) {
        isRobot[up_idx] = 1;
        dur[up_idx]--;
    }
}

int countOldBelts() {
    int cnt = 0;
    for (int i = 0; i < 2*N; i++) {
        if (dur[i] == 0)    cnt++;
    }

    return cnt;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < 2*N; i++) {
        cin >> dur[i];
    }

    up_idx = 0;
    down_idx = N-1;

    while (true) {
        rotateBelt();
        moveRobots();
        upRobot();

        int cnt = countOldBelts();
        if (cnt >= K)   break;
        phase++;
    }

    cout << phase;
}