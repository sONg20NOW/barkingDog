#include <bits/stdc++.h>
using namespace std;
int vis[1000001];

int main() {
    fill(vis, vis+1000001, -1);
    int F, S, G, U, D;
    // F : 총 F층
    // S : 강호가 있는 층
    // G : 스타트링크가 있는 층
    cin >> F >> S >> G >> U >> D;

    queue<int> Q;
    Q.push(S);
    vis[S] = 0;
    while(!Q.empty()) {
        int cur = Q.front();    Q.pop();
        if (cur == G) {
            cout << vis[cur] << '\n';
            return 0;
        }
        for (int next : {cur + U, cur - D}) {
            if (next <= 0 || next > F)  continue;
            if (vis[next] >= 0)  continue;
            vis[next] = vis[cur] + 1;
            Q.push(next);
        }
    }

    cout << "use the stairs" << '\n';
    return 0;
}