#include <bits/stdc++.h>
using namespace std;
const int MX = 13;
int N, M;
char board[MX][MX];
char board2[MX][MX];
int visited[MX][MX][MX][MX];

int rx, ry, bx, by;

queue<vector<int>> Q;
void printBoard() {
    cout << "-----" << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

// dir 방향으로 기울이기. 파란 공이 들어가면 -1 반환. 빨간 공은 1. 둘 중 무엇도 아니면 0.
int tilt(char board2[MX][MX], int dir) {
    stack<char> balls;
    switch (dir)
    {
    case 0:
    // 왼쪽으로
        for (int i = 0; i < N; i++) {
            for (int j = M - 1; j >= 0; j--) {
                if (board2[i][j] == 'R' || board2[i][j] == 'B') {
                    balls.push(board2[i][j]);
                    board2[i][j] = '.';
                }
                else if (board2[i][j] == '#' && !balls.empty()) {
                    int diff = 0;
                    while (!balls.empty()) {
                        board2[i][j + ++diff] = balls.top();
                        balls.pop();
                    }
                } else if (board2[i][j] == 'O' && !balls.empty()) {
                    bool redIn = false, blueIn = false;
                    while(!balls.empty()) {
                        char b = balls.top();   balls.pop();
                        if (b == 'R')   redIn = true;
                        else if (b == 'B')  blueIn = true;
                    }
                    if (blueIn) return -1;
                    if (redIn) return 1;
                }
            }
        }
        break;
    case 1:
    // 오른쪽으로
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board2[i][j] == 'R' || board2[i][j] == 'B') {
                    balls.push(board2[i][j]);
                    board2[i][j] = '.';
                }
                else if (board2[i][j] == '#' && !balls.empty()) {
                    int diff = 0;
                    while (!balls.empty()) {
                        board2[i][j - ++diff] = balls.top();
                        balls.pop();
                    }
                } else if (board2[i][j] == 'O' && !balls.empty()) {
                    bool redIn = false, blueIn = false;
                    while(!balls.empty()) {
                        char b = balls.top();   balls.pop();
                        if (b == 'R')   redIn = true;
                        else if (b == 'B')  blueIn = true;
                    }
                    if (blueIn) return -1;
                    if (redIn) return 1;
                }
            }
        }
        break; 
    case 2:
    // 아래로
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board2[j][i] == 'R' || board2[j][i] == 'B') {
                    balls.push(board2[j][i]);
                    board2[j][i] = '.';
                }
                else if (board2[j][i] == '#' && !balls.empty()) {
                    int diff = 0;
                    while (!balls.empty()) {
                        board2[j - ++diff][i] = balls.top();
                        balls.pop();
                    }
                } else if (board2[j][i] == 'O' && !balls.empty()) {
                    bool redIn = false, blueIn = false;
                    while(!balls.empty()) {
                        char b = balls.top();   balls.pop();
                        if (b == 'R')   redIn = true;
                        else if (b == 'B')  blueIn = true;
                    }
                    if (blueIn) return -1;
                    if (redIn) return 1;
                }
            }
        }
        break; 
    case 3:
        for (int i = 0; i < M; i++) {
            for (int j = N - 1; j >= 0; j--) {
                if (board2[j][i] == 'R' || board2[j][i] == 'B') {
                    balls.push(board2[j][i]);
                    board2[j][i] = '.';
                }
                else if (board2[j][i] == '#' && !balls.empty()) {
                    int diff = 0;
                    while (!balls.empty()) {
                        board2[j + ++diff][i] = balls.top();
                        balls.pop();
                    }
                } else if (board2[j][i] == 'O' && !balls.empty()) {
                    bool redIn = false, blueIn = false;
                    while(!balls.empty()) {
                        char b = balls.top();   balls.pop();
                        if (b == 'R')   redIn = true;
                        else if (b == 'B')  blueIn = true;
                    }
                    if (blueIn) return -1;
                    if (redIn) return 1;
                }
            }
        }
        break; 
    default:
        break;
    }
    
    return 0;
}

// board2에서 볼 위치 찾기
void findBalls() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board2[i][j] == 'R') {
                rx = i; ry = j;
            } else if (board2[i][j] == 'B') {
                bx = i; by = j;
            }
        }
    }
}

int main() {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            board2[i][j] = board[i][j];
    findBalls();
    visited[rx][ry][bx][by] = 1;

    Q.push({0});
    Q.push({1});
    Q.push({2});
    Q.push({3});

    while(!Q.empty()) {
        vector<int> cur = Q.front();    Q.pop();
        if (cur.size() > 10) {
            cout << -1 << '\n';
            return 0;
        }
        // board2 초기화
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++)
                board2[i][j] = board[i][j];

        // 기울이기 진행
        for (int i = 0; i < cur.size(); i++) {
            int res = tilt(board2, cur[i]);
            findBalls();
            if (i == cur.size() - 1) {
                if (res == 1) {
                    cout << cur.size() << '\n';
                    return 0;
                } else if (res == 0 && !visited[rx][ry][bx][by]) {
                    visited[rx][ry][bx][by] = 1;

                    vector<int> temp = cur;
                    temp.push_back(0);
                    Q.push(temp);
                    temp.pop_back();

                    temp.push_back(1);
                    Q.push(temp);
                    temp.pop_back();

                    temp.push_back(2);
                    Q.push(temp);
                    temp.pop_back();

                    temp.push_back(3);
                    Q.push(temp);
                    temp.pop_back();
                } 
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}