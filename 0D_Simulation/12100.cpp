#include <bits/stdc++.h>
using namespace std;

struct Node {
    int num;
    bool comp;
};

int N;
int board[20][20];
int temp[20][20];
// 최대 5번 이동 -> 상하좌우를 0~3에 대입했을 때
// 0~3을 순서있게 길이가 5인 수열을 뽑는 문제
int arr[5];
int mx_num = 0;

void PrintTemp() {
    cout << "---------" << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << temp[i][j] << ' ';
        }
        cout << '\n';
    }
}

// temp 배열에서 가장 큰 수를 반환하는 함수
int BiggestNum() {
    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mx = max(mx, temp[i][j]);
        }
    }

    return mx;
}

// temp 배열을 dir 방향으로 민 결과를 temp 배열에 반영하는 함수
void Swipe(int dir) {
    deque<Node> ST;
    switch (dir)
    {
    case 0:
        // 왼쪽으로 밀기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int cur = temp[i][j];
                if (cur == 0)   continue;
                if (ST.empty() || ST.back().comp || ST.back().num != cur)   
                    ST.push_back({cur, false});
                else {
                    ST.pop_back();   ST.push_back({2 * cur, true});
                }
            }

            for (int j = 0; j < N; j++) {
                if (!ST.empty()) {
                    temp[i][j] = ST.front().num;    ST.pop_front();
                } else {
                    temp[i][j] = 0;
                }
            }
        }
        return;
    case 1:
        // 오른쪽으로 밀기
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                int cur = temp[i][j];
                if (cur == 0)   continue;
                if (ST.empty() || ST.back().comp || ST.back().num != cur)   
                    ST.push_back({cur, false});
                else {
                    ST.pop_back();   ST.push_back({2 * cur, true});
                }
            }

            for (int j = N - 1; j >= 0; j--) {
                if (!ST.empty()) {
                    temp[i][j] = ST.front().num;    ST.pop_front();
                } else {
                    temp[i][j] = 0;
                }
            }
        }
        return;
    case 2:
        // 위로 밀기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int cur = temp[j][i];
                if (cur == 0)   continue;
                if (ST.empty() || ST.back().comp || ST.back().num != cur)   
                    ST.push_back({cur, false});
                else {
                    ST.pop_back();   ST.push_back({2 * cur, true});
                }
            }

            for (int j = 0; j < N; j++) {
                if (!ST.empty()) {
                    temp[j][i] = ST.front().num;    ST.pop_front();
                } else {
                    temp[j][i] = 0;
                }
            }
        }
        return;
    case 3:
        // 아래로 밀기
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                int cur = temp[j][i];
                if (cur == 0)   continue;
                if (ST.empty() || ST.back().comp || ST.back().num != cur)   
                    ST.push_back({cur, false});
                else {
                    ST.pop_back();   ST.push_back({2 * cur, true});
                }
            }

            for (int j = N - 1; j >= 0; j--) {
                if (!ST.empty()) {
                    temp[j][i] = ST.front().num;    ST.pop_front();
                } else {
                    temp[j][i] = 0;
                }
            }
        }
        return;

    default:
        return;
    }
}

void func(int i) {
    if (i == 5) {
        // temp 초기화
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                temp[x][y] = board[x][y];
            }
        }
        for (int a : arr) {
            Swipe(a);
        }
        mx_num = max(mx_num, BiggestNum());

        return;
    }

    arr[i] = 0;
    func(i + 1);

    arr[i] = 1;
    func(i + 1);

    arr[i] = 2;
    func(i + 1);

    arr[i] = 3;
    func(i + 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            temp[x][y] = board[x][y];
        }
    }
    // Swipe(0);
    // PrintTemp();

    func(0);
    cout << mx_num;
}