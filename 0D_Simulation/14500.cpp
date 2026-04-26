#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[502][502];

int ans = 0;

pair<int,int> candits[19][4] = {
    // 일자
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    // 사각형
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    // ㄴ자
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    // 리버스 ㄴ자
    {{2, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    // z자
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
    // ㅗ자
    {{0, 0}, {0, 1}, {1, 1}, {0, 2}},
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
};

int innerRes(int x, int y, int i) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
        pair<int,int> coord = candits[i][j];
        int dx = coord.first + x;
        int dy = coord.second + y;
        if (dx < 0 || dy < 0 || dx >= N || dy >= M) return -1;
        sum += board[dx][dy];
    }

    return sum;
}

void res(int x, int y) {
    for (int i = 0; i < 19; i++) {
        ans = max(ans, innerRes(x, y, i));
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            res(x, y);
        }
    }

    cout << ans;
    
}