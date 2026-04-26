#include <bits/stdc++.h>
using namespace std;

int N;
int x, y, d, g;
int board[101][101];
pair<int,int> dir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void PrintBoard() {
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int FindRectangles() {
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
                cnt++;
            }
        }
    }

    return cnt;
}

deque<int> V;
void Progress() {
    V.push_back(d);
    while (g--) {
        int s = V.size();
        for (int i = s - 1; i >= 0; i--) {
            V.push_back((V[i] + 1) % 4);
        }
    }

    // for (int a : V) {
    //     cout << "{" << dir[a].first << ", " << dir[a].second << "}" << " - ";
    // }
    // cout << '\n';

    board[y][x] = 1;
    while(!V.empty()) {
        int a = V.front();
        y += dir[a].first;
        x += dir[a].second;
        board[y][x] = 1;
        V.pop_front();
    }

    return;
}

int main() {
    cin >> N;
    while (N--) {
        cin >> x >> y >> d >> g;
        Progress();
        // PrintBoard();
    }

    cout << FindRectangles();
}

