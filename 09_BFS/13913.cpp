#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int T[100001];

int main() {
    fill(T, T + 100001, -1);

    int N, K;
    cin >> N >> K;

    queue<int> Q;
    Q.push(N);
    T[N] = -100;
    while (!Q.empty()) {
        int cur = Q.front();    Q.pop();
        if (cur == K) {
            int temp = cur;
            stack<int> path;
            while(temp >= 0) {
                path.push(temp);
                temp = T[temp];
            }

            cout << path.size() - 1 << '\n';
            while (!path.empty()) {
                cout << path.top() << ' ';
                path.pop();
            }

            return 0;
        }
        for (int i : {cur - 1, cur + 1, cur * 2}) {
            if (i < 0 || i > 100000)    continue;
            if (T[i] >= 0 || T[i] == -100)  continue;
            T[i] = cur;
            Q.push(i);
        }
    }
}