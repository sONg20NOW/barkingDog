#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];

int min_diff = 40 * 100 * 100;
int total_popul;

void innerFunc(int d1, int d2, int x, int y) {
    int population[5] = {0, 0, 0, 0, 0};
    // 1번 선거구
    for (int r = 1; r < x + d1; r++) {
        for (int c = 1; c <= y; c++) {
            if (r + c >= x + y) continue;
            population[0] += board[r][c];
        }
    }
    // 2번 선거구
    for (int r = 1; r <= x + d2; r++) {
        for (int c = y + 1; c <= N; c++) {
            if (r - c >= x - y) continue;
            population[1] += board[r][c];
        }
    }
    // 3번 선거구
    for (int r = x+d1; r <= N; r++) {
        for (int c = 1; c < y-d1+d2; c++) {
            if (r - c <= x - y + 2 * d1) continue;
            population[2] += board[r][c];
        }
    }
    // 4번 선거구
    for (int r = x+d2+1; r <= N; r++) {
        for (int c = y-d1+d2; c <= N; c++) {
            if (r + c <= x + y +2 * d2) continue;
            population[3] += board[r][c];
        }
    }
    // 5번 선거구
    population[4] = total_popul;
    for (int i = 0; i < 4; i++) {
        population[4] -= population[i];
    }

    // cout << "===population===\n";
    // for (int i = 0; i < 5; i++) {
    //     cout << population[i] << ' ';
    // } 
    // cout << '\n';
    // cout << "max: " << *max_element(population, population + 5) << '\n';
    // cout << "min: " << *min_element(population, population + 5) << '\n';

    // 최대 인구수와 최소 인구수 빼기
    min_diff = min(min_diff, *max_element(population, population + 5) - *min_element(population, population + 5));
}

// x, y를 정하고 내부 함수로 이동
void func(int d1, int d2) {
    for (int x = 1; x + d1 + d2 <= N; x++) {
        for (int y = d1 + 1; y + d2 <= N; y++) {
            innerFunc(d1, d2, x, y);
        }
    }
}


int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            total_popul += board[i][j];
        }
    }

    // d1 + d2 + 1 <= N인 d1과 d2 고르기
    // d1과 d2는 각각 N-2 이하
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= N-1-i; j++) {
            // x와 y 고르기
            // 1 <= x && x+d1+d2 <= N
            // 1 <= y-d1 && y+d2 <= N
            func(i, j);
        }
    }

    // innerFunc(1, 1, 3, 3);

    cout << min_diff;
}