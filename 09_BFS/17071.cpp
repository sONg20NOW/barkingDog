#include <bits/stdc++.h>
using namespace std;
int vis[2][500001];

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> Q;
    Q.push(N);
    vis[0][N] = 100;

    int A = 0;

    while(!Q.empty()) {
        if (K > 500000) {
            break;
        }
        int size = Q.size();
        while(size--) {
            int cur = Q.front();    Q.pop();

            // cout << "cur: " << cur << '\n';
            if (vis[A % 2][K]) {
                cout << A << '\n';
                return 0;
            }
            
            for (int next : {cur - 1, cur + 1, 2 * cur}) {
                if (next < 0 || next > 500000)  continue;
                if (vis[(A+1)%2][next] != 0) continue;
                Q.push(next);
                // cout << "push: " << next << '\n';
                vis[(A+1)%2][next] = A + 1;
            }
        }
        K += ++A;
    }

    cout << -1 << '\n';
    return 0;
}