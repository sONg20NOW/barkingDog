#include <bits/stdc++.h>
using namespace std;

int dices[10];

// 0~9를 네개로 나누기
// => arr[10]의 각 수를 0~3에 할당하기.
int arr[10];

int max_score = -1;

// 0: 시작점
// 1 ~ 20 : 일반경로
// 21: 도착점
// 22 ~ 24 : 10부터
// 25 ~ 26 : 20부터
// 27 ~ 29 : 30부터
// 30 ~ 32 : 25부터
int board[33] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, -1,
13, 16, 19, 
22, 24,
28, 27, 26,
25, 30, 35
};

int horses[4];

// i번째 말을 한 칸 이동시키기
void moveHorseOneStep(int i, bool blue) {
    if (horses[i] == 21)    return;

    if (blue) {
        switch (horses[i])
        {
        case 5:
            horses[i] = 22;
            break;
        case 10:
            horses[i] = 25;
            break;
        case 15:
            horses[i] = 27;
            break;
        } 
    } else {
        switch (horses[i])
        {
        case 24:
        case 26:
        case 29:
            horses[i] = 30;
            break;
        case 32:
            horses[i] = 20;
            break;
        
        default:
            horses[i]++;
            break;
        }
    }

}

// i번째 말을 n칸 이동시키기 (그리고 점수 반환)
// -1을 반환한다는 건 불가능한 경우 - 도착지에 이미 다른 말이 있는 경우
void moveHorse(int i, int n) {
    bool blue = false;
    if (horses[i] == 5 || horses[i] == 10 || horses[i] == 15) {
        blue = true;
    }
    while (n--) {
        moveHorseOneStep(i, blue);
        blue = false;
    }
}

// arr에 저장된 수를 가지고 시뮬레이션 돌리는 함수
void simulation() {
    // horses 초기화
    fill(horses, horses + 4, 0);
    int score = 0;
    for (int i = 0; i < 10; i++) {
        int cur_dice = dices[i];
        int cur_idx = arr[i];

        moveHorse(cur_idx, cur_dice);
        int next_loc = horses[cur_idx];
        for (int j = 0; j < 4; j++) {
            if (j == cur_idx)   continue;
            if (horses[j] == horses[cur_idx] && horses[cur_idx] != 21) {
                return;
            }
        }

        int result = board[next_loc];
        if (result < 0) continue;

        score += result;
    }

    max_score = max(max_score, score);
}

// arr 수를 특정시키는 백트래킹
void func(int k) {
    if (k == 10) {
        simulation();

        return;
    }

    for (int i = 0; i < 4; i++) {
        arr[k] = i;
        func(k + 1);
    }
}


int main() {
    for (int i = 0; i < 10; i++) {
        cin >> dices[i];
    }

    func(0);

    cout << max_score;
}