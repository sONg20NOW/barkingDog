#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int board[40][40];
int shape[10][10];
int r, c;

// x,y가 N x M 밖에 있는지 확인하는 함수
bool OOP(int x, int y) {
    return (x >= 0 && x < N && y >=0 && y < M);
}

// x, y는 왼쪽 시작점, dir는 0~3
bool Stick(int x, int y, int dir) {
    switch (dir)
    {
    case 0:
        if (!OOP(x + r - 1, y + c - 1))  return false;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (shape[i][j] == 1 && board[i + x][j + y] == 1)
                    return false;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i + x][j + y] += shape[i][j];
            }
        }
        return true;
        break;
    case 1:
        if (!OOP(x + c - 1, y + r - 1))  return false;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                if (shape[r - 1 - j][i] == 1 && board[i + x][j + y] == 1)
                    return false;
            }
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                board[i + x][j + y] += shape[r - 1 - j][i];
            }
        }
        return true;
        break;
    case 2:
        if (!OOP(x + r - 1, y + c - 1))  return false;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (shape[r - 1 - i][c - 1 - j] == 1 && board[i + x][j + y] == 1)
                    return false;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i + x][j + y] += shape[r - 1 - i][c - 1 - j];
            }
        }
        return true;
        break;
    case 3:
        if (!OOP(x + c - 1, y + r - 1))  return false;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                if (shape[j][c - 1 - i] == 1 && board[i + x][j + y] == 1)
                    return false;
            }
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                board[i + x][j + y] += shape[j][c - 1 - i];
            }
        }
        return true;
        break;
    
    default:
        break;
    }
}

void Try() {
    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (Stick(i, j, dir))   return;
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int k = 0; k < K; k++) {
        // 입력 받기
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cin >> shape[i][j];
        }

        Try();
    }

    // cout << "-----------" << '\n';
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt += (board[i][j] == 1);
        }
    }

    cout << cnt;
}