#include <bits/stdc++.h>
using namespace std;

// 대문자 + 32 = 소문자
const int UTL = 32;
const int MX = 100;
string board[MX];
int vis[MX][MX];
pair<int,int> dir[4] = {
    {0,1},{0,-1},{1,0},{-1,0}
};

int CountKey(int key) {
    int count = 0;
    while(key > 0) {
        if (key % 2 == 1)   count++;
        key = key >> 1;
    }
    return count;
}

bool AddKey(int& keys, char c) {
    if (c >= 'a' && c <= 'z') {
        keys = keys | (1 << (c - 'a'));
        return true;
    }
    return false;
}

bool ExistKey(int keys, char door) {
    if (door >= 'A' && door <= 'Z') {
        if (((keys >> (door + 32 - 'a')) % 2 == 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        queue<pair<int,int>> Q;
        queue<pair<int,int>> locked_Q[26];
        // key를 비트로 저장하는 정수
        int keys = 0;
        int docs = 0;

        int h, w;
        cin >> h >> w;

        for (int i = 0; i < h; i++) {
            cin >> board[i];
            // 외곽에 있는 키 줍기
            for (int j = 0; j < w; j++) {
                if (i == 0 || j == 0 || i == h-1 || j == w-1) {
                    if (AddKey(keys, board[i][j]))
                        board[i][j] = '.';
                }
            }
        }

        string s;
        cin >> s;
        if (s != "0") {
            for (char c : s) {
                AddKey(keys, c);
            }
        }

        // 빌딩 외곽 시작점 넣기
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || j == 0 || i == h-1 || j == w-1) {
                    if (board[i][j] == '.') {
                        // cout << "start pushed1: " << i << ',' << j << '\n';
                        Q.push({i ,j});
                        vis[i][j] = 1;
                    } else if (AddKey(keys, board[i][j])) {
                        // cout << "start pushed2: " << i << ',' << j << '\n';
                        board[i][j] = '.';
                        Q.push({i ,j});
                        vis[i][j] = 1;
                    } else if (board[i][j] == '$') {
                        board[i][j] = '.';
                        Q.push({i,j});
                        vis[i][j] = 1;
                        docs++;
                    } 
                }
            }
        }

        // 외곽 문 열 수 있는 곳 열기
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || j == 0 || i == h-1 || j == w-1) {
                    if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                        if (ExistKey(keys, board[i][j])) {
                            // cout << "start pushed2: " << i << ',' << j << '\n';
                            board[i][j] = '.';
                            Q.push({i, j});
                            vis[i][j] = 1;
                        } else {
                            locked_Q[board[i][j] - 'A'].push({i,j});
                        }
                    }
                    
                }
            }
        }


        while(!Q.empty()) {
            pair<int,int> cur = Q.front(); Q.pop();
            // cout << '{' << cur.first << ',' << cur.second << '}' << "->" << '\n';
            for (pair<int,int> d : dir) {
                int dx = d.first + cur.first;
                int dy = d.second + cur.second;
                if (dx < 0 || dy < 0 || dx >= h || dy >= w) continue;
                if (vis[dx][dy] || board[dx][dy] == '*')    continue;
                if (board[dx][dy] >= 'A' && board[dx][dy] <= 'Z') {
                    if (ExistKey(keys, board[dx][dy])) {
                        board[dx][dy] = '.';
                        Q.push({dx, dy});
                        vis[dx][dy] = 1;
                    } else {
                        locked_Q[board[dx][dy] - 'A'].push({dx,dy});
                        continue;
                    }
                } else if (AddKey(keys, board[dx][dy])) {
                    // cout << "key acquired!: " << board[dx][dy] << '\n';
                    while (!locked_Q[board[dx][dy] - 'a'].empty()) {
                        pair<int,int> locked = locked_Q[board[dx][dy] - 'a'].front(); locked_Q[board[dx][dy] - 'a'].pop();
                        Q.push({locked.first, locked.second});
                    }

                    board[dx][dy] = '.';
                    Q.push({dx, dy});
                    vis[dx][dy] = 1;
                } else if (board[dx][dy] == '.') {
                    Q.push({dx, dy});
                    vis[dx][dy] = 1;
                } else if (board[dx][dy] == '$') {
                    board[dx][dy] = '.';
                    Q.push({dx, dy});
                    vis[dx][dy] = 1;
                    docs++;
                }
            }
        }

        cout << docs << '\n';

        // vis 체크를 각 열쇠를 갖고 가본 적 있는지로 체크
        // 현재 열쇠를 뭐뭐 가지고 있는지 어떻게 기억하지?
        // 새 열쇠를 얻을 때마다 vis[n] 증가시키기? vis[n][x][y] 이런 느낌으로?

        // vis 비우기
        for (int i = 0; i < h; i++) fill(vis[i], vis[i] + w, 0);
    }
}