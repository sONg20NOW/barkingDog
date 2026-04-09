#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[50][50];

int chicken_cnt;
vector<pair<int,int>> chickenResturants;
int arr[13];

int min_chicken_dist = 13 * 100;

// {x, y}의 치킨 거리를 구하는 함수
int getChickenDist(int x, int y) {

    int min_dist = 50;
    for (int i = 0; i < M; i++) {
        int chicken_idx = arr[i];
        pair<int,int> chicken_addr = chickenResturants[chicken_idx];

        min_dist = min(min_dist, abs(x - chicken_addr.first) + abs(y - chicken_addr.second));
    }

    return min_dist;
}

// 각 집에서 치킨 거리를 구해서 도시의 치킨 거리를 구하는 함수
int getCityChikenDist() {
    int dist_sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                dist_sum += getChickenDist(i, j);
            }
        }
    }

    return dist_sum;
}

// 0 ~ chicken_cnt 중에 길이가 M인 순서 유지 수열 뽑기
void func(int idx, int last_i) {
    if (idx == M) {
        min_chicken_dist = min(min_chicken_dist, getCityChikenDist());
        return;
    }

    for (int i = last_i + 1; i < chicken_cnt; i++) {
        arr[idx] = i;
        func(idx + 1, i);
    }
    
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chicken_cnt++;
                chickenResturants.push_back({i, j});
            }
        }
    }

    func(0, -1);

    cout << min_chicken_dist << '\n';
}