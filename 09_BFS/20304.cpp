#include <bits/stdc++.h>
using namespace std;
int dis[1000001];

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    queue<int> Q;

    for(int i = 0; i < M; i++) {
        int t;
        cin >> t;
        Q.push(t);
        dis[t] = 1;
    }

    int max = 0;

    while(!Q.empty()) {
        int cur = Q.front();    Q.pop();
        if (dis[cur] > max) max = dis[cur];
        for (int i = 0; (1 << i) <= N; i++) {
            int next = cur ^ (1 << i);
            if (next > N)   continue;
            if (dis[next] != 0) continue;
            dis[next] = dis[cur] + 1;
            Q.push(next);
        }
    }

    cout << max - 1 << '\n';
}