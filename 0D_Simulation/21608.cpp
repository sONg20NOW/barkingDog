#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 22;
// zero-index
int board[MX][MX];

const pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};

int student_cnt;

// 좋아하는 학생의 번호
int bf[402][4];

// 학생이 앉을 순서
int order[402];

struct Seat {
    int r, c, bf_cnt, blank_cnt;
};

void printBoard() {
    cout << "=== print board ===\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool compare(Seat a, Seat b) {
    if (a.bf_cnt == b.bf_cnt) {
        if (a.blank_cnt == b.blank_cnt) {
            if (a.r == b.r) {
                return a.c < b.c;
            }
            return a.r < b.r;
        }
        return a.blank_cnt > b.blank_cnt;
    }
    return a.bf_cnt > b.bf_cnt;
}

// 학생 번호 st가 (r,c)에 있을 때 인접한 칸에 좋아하는 학생의 수와 빈칸의 수
Seat adjInfo(int st, int r, int c) {
    int cnt = 0;
    int blank_cnt = 0;
    for (pair<int,int> d : dirs) {
        int dx = r + d.first;
        int dy = c + d.second;
        if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
        if (board[dx][dy] == 0) {
            blank_cnt++;
            continue;
        }
        for (int t_st : bf[st]) {
            if (t_st == board[dx][dy]) {
                cnt++;
                break;
            }
        }
    }

    return {r, c, cnt, blank_cnt};
}

// 학생들의 만족도를 구하는 함수
int satisf() {
    int score = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cur_st = board[i][j];
            Seat res = adjInfo(cur_st, i, j);
            switch (res.bf_cnt)
            {
            case 0:
                score += 0;
                break;
            case 1:
                score += 1;
                break;
            case 2:
                score += 10;
                break;
            case 3:
                score += 100;
                break;
            case 4:
                score += 1000;
                break;
         
            default:
                break;
            }
        }
    }

    return score;
}

int main() {
    cin >> N;
    
    student_cnt = N * N;

    for (int i = 1; i <= student_cnt; i++) {
        int a;
        cin >> a;
        order[i-1] = a;
        for (int j = 0; j < 4; j++) {
            cin >> bf[a][j];
        }
    }

    for (int i = 0; i < student_cnt; i++) {
        int cur_st = order[i];

        vector<Seat> candidates = {};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 0) {
                    Seat res = adjInfo(cur_st, i, j);
                    candidates.push_back(res);
                }
            }
        }

        sort(candidates.begin(), candidates.end(), compare);
        Seat ans = candidates[0];
        board[ans.r][ans.c] = cur_st;
    }

    cout << satisf();
}