#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1001;
int D[MX][3];
int cost[MX][3];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >>  cost[i][j];
            // 초기값 정하기
            if (i == 0) {
                D[i][j] = cost[i][j];
            }
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int min_cost = 1001;
            if (j != 0) min_cost = min(min_cost, D[i-1][0]);
            if (j != 1) min_cost = min(min_cost, D[i-1][1]);
            if (j != 2) min_cost = min(min_cost, D[i-1][2]);
            D[i][j] = min_cost + cost[i][j];
        }
    }

    int ans = D[N-1][0];
    for (int j = 1; j < 3; j++) {
        ans = min(ans, D[N-1][j]);
    }

    cout << ans;
}