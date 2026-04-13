#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[12][12];
int board[12][12][1011];
int energy[12][12];
int death[12][12];

pair<int,int> adj[8] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
    {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

int sum;

void printEnergy() {
    cout << "Energy)\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << energy[i][j] << ' ';
        }
        cout << '\n';
    }
}

void func() {
    // 봄
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
        int grow_cnt = 0;
            for (int age = 1; age <= 1010; age++) {
                int tree_cnt = board[i][j][age] - grow_cnt;

                if (tree_cnt < 0) {
                    cout << "something is wrong!\n";
                    return;
                }
                if (tree_cnt == 0)  {
                    grow_cnt = 0;
                    continue;
                }
                
                grow_cnt = min(tree_cnt, (energy[i][j] / age));
                energy[i][j] -= grow_cnt * age;
                board[i][j][age + 1] += grow_cnt;
                board[i][j][age] -= grow_cnt;
                // cout << "year: " << K << " - (" << i << ", " << j <<")'s age: " << age << "/ grow cnt: " << grow_cnt << "/ tree cnt: " << tree_cnt << '\n';
                
                int death_cnt = tree_cnt - grow_cnt;
                sum -= death_cnt;
                board[i][j][age] -= death_cnt;
                death[i][j] += (age >> 1) * death_cnt;

            }
        }
    }

    // 여름
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            energy[i][j] += death[i][j];
            death[i][j] = 0;
        }
    }

    // 가을
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= 202; k++) {
                int age = 5 * k;
                if (!board[i][j][age])  continue;
                int tree_cnt = board[i][j][age];
                for (pair<int,int> d : adj) {
                    int dx = d.first + i;
                    int dy = d.second + j;
                    if (dx < 1 || dy < 1 || dx > N || dy > N)   continue;
                    board[dx][dy][1] += tree_cnt;
                    sum += tree_cnt;
                }
            }
        }
    }

    // 겨울
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            energy[i][j] += A[i][j];
        }
    }

    // printEnergy();
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    sum += M;

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        board[x][y][z]++;
    }

    // 양분 5로 초기화
    for (int i = 1; i <= N; i++) {
        fill(energy[i], energy[i] + N + 1, 5);
    }

    while(K--) {
        func();
    }

    cout << sum;
}