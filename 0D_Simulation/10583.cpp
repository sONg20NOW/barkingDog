#include <bits/stdc++.h>
using namespace std;

struct Camera {
    int x, y, cam;
};

int N, M;
int board[8][8];
int cam_dirs[8];
Camera cams[8];
int k;
int min_blind_cnt = 64;

pair<int,int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void GoThrough(int temp[8][8], int x, int y, int dir) {
    switch (dir)
    {
    case 0:
        /* code */
        y -= 1;
        while(x >= 0 && x < N && y >= 0 && y <M) {
            if (temp[x][y] == 6)   break;
            else if (temp[x][y] == 0) {
                temp[x][y] = '#';
            }
            y -= 1;
        }
        break;
    case 1:
        /* code */
        x -= 1;
        while(x >= 0 && x < N && y >= 0 && y <M) {
            if (temp[x][y] == 6)   break;
            else if (temp[x][y] == 0) {
                temp[x][y] = '#';
            }
            x -= 1;
        }
        break;    
    case 2:
        /* code */
        y += 1;
        while(x >= 0 && x < N && y >= 0 && y <M) {
            if (temp[x][y] == 6)   break;
            else if (temp[x][y] == 0) {
                temp[x][y] = '#';
            }
            y += 1;
        }
        break;    
    case 3:
        /* code */
        x += 1;
        while(x >= 0 && x < N && y >= 0 && y <M) {
            if (temp[x][y] == 6)   break;
            else if (temp[x][y] == 0) {
                temp[x][y] = '#';
            }
            x += 1;
        }
        break; 
    default:
        break;
    }
}

void Simulate() {
    int cnt = 0;
    int temp[8][8];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        Camera cam = cams[i];
        int dir = cam_dirs[i];
        switch (cam.cam)
        {
        case 1:
            GoThrough(temp, cam.x, cam.y, dir);
            break;
        case 2: 
            GoThrough(temp, cam.x, cam.y, dir);
            GoThrough(temp, cam.x, cam.y, (dir + 2 > 3 ? dir + 2 - 4 : dir + 2));
            break;
        case 3:
            GoThrough(temp, cam.x, cam.y, dir);
            GoThrough(temp, cam.x, cam.y, (dir + 1 > 3 ? dir + 1 - 4 : dir + 1));
            break;
        case 4:
            GoThrough(temp, cam.x, cam.y, dir);
            GoThrough(temp, cam.x, cam.y, (dir + 1 > 3 ? dir + 1 - 4 : dir + 1));
            GoThrough(temp, cam.x, cam.y, (dir - 1 < 0 ? dir - 1 + 4 : dir - 1));
            break;
        case 5:
            GoThrough(temp, cam.x, cam.y, 0);
            GoThrough(temp, cam.x, cam.y, 1);
            GoThrough(temp, cam.x, cam.y, 2);
            GoThrough(temp, cam.x, cam.y, 3);
        default:
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 0)   cnt++;
        }
    }

    min_blind_cnt = min(min_blind_cnt, cnt);
}

// i번쨰 뽑을 차례
void func(int i) {

    if (i == k) {
        Simulate();
        return;
    }

    cam_dirs[i] = 0;
    func(i + 1);

    cam_dirs[i] = 1;
    func(i + 1);

    cam_dirs[i] = 2;
    func(i + 1);

    cam_dirs[i] = 3;
    func(i + 1);
}

int main() {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] > 0 && board[i][j] < 6) {
                cams[k++] = {i, j, board[i][j]};
            }
        }
    }

    // 1~4의 수를 k개 뽑는 문제 (순서 o)
    func(0);

    cout << min_blind_cnt << '\n';
}