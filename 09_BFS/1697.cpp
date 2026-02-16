#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int vis[100002];

int main() {
    fill(vis, vis + 100002, -1);

    int N, K;
    cin >> N >> K;

    queue<int> Q;
    vis[N] = 0;
    Q.push(N);

    while(!Q.empty()) {
        int cur = Q.front();    Q.pop();
        if (cur == K) {
            cout << vis[cur] << '\n';
            return 0;
        }
        for (int i : {cur - 1, cur + 1, 2 * cur}) {
            if (i < 0 || i > 100001)    continue;
            if (vis[i] >= 0) continue;
            vis[i] = vis[cur] + 1;
            Q.push(i);
        }
    }
}