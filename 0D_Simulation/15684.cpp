#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int garos[31][10];

queue<vector<int>> Q;

pair<int,int> IntToAB(int n) {
    int a = n / (N - 1);
    int b = n % (N - 1);
    return {a + 1, b + 1};
}

bool progressAll() {
    for (int i = 1; i <= N; i++) {
        int n = i;
        int h = 1;
        while (h < H + 1) {
            // 왼쪽으로 가는 길이 있다면
            if (n - 1 >= 1 && garos[h][n - 1]) {
                n--;
            } else if (n <= N - 1 && garos[h][n]) {
                n++;
            }
            h++;
        }
        if (n != i) return false;
    }
    return true;
}

bool progress(vector<int> V) {
    for (int a : V) {
        pair<int,int> AB = IntToAB(a);
        garos[AB.first][AB.second] = 1;
    }

    bool res = progressAll();

    for (int a : V) {
        pair<int,int> AB = IntToAB(a);
        garos[AB.first][AB.second] = 0;
    }

    return res;
}

bool canPut(int n) {
    pair<int,int> AB = IntToAB(n);
    if (garos[AB.first][AB.second]) return false;
    if (AB.second - 1 >= 0 && garos[AB.first][AB.second - 1])   return false;
    if (AB.second + 1 < N && garos[AB.first][AB.second + 1])    return false;
    return true;
}

int BFS() {
    Q.push({});
    while(!Q.empty()) {
        vector<int> cur = Q.front();    Q.pop();
        if (progress(cur)) {
            return cur.size();
        }
        // if (cur.size() == 3) {
        //     for (int a : cur)   cout << a << ' ';
        //     cout << '\n';
        // }
        if (cur.size() >= 4) {
            return -1;
        }
        for (int i = (cur.size() == 0 ? 0 : cur[cur.size() - 1] + 1); i < (N -1) * H; i++) {
            if (!canPut(i)) continue;
            vector<int> temp = cur;
            temp.push_back(i);
            Q.push(temp);
        }
    }

    return -1;
}

int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        garos[a][b] = 1;
    }

    cout << BFS();
}