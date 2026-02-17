#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int MX = 100001;
int T[MX];

int main() {
    fill(T, T + MX, -1);

    int N, K;
    cin >> N >> K;

    deque<int> Q;
    T[N] = 0;
    Q.push_back(N);
    while (!Q.empty()) {
        int cur = Q.front();    Q.pop_front();
        if (cur == K) {
            cout << T[cur] << '\n';
            return 0;
        }
        
        int tp = cur * 2;
        if (tp >= 0 && tp < MX && T[tp] == -1) {
            T[tp] = T[cur];
            Q.push_front(tp);
        }


        // 걷는 경우에 대해서 큐에 추가
        for (int i : {cur - 1, cur + 1}) {
            if (i < 0 || i >= MX)    continue;
            if (T[i] >= 0)  continue;
            T[i] = T[cur] + 1;
            Q.push_back(i);
        }
    }
}