#include <bits/stdc++.h>
using namespace std;
const int MX = 100001;
int students[MX];
int choosed[MX];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> students[i];
            choosed[students[i]]++;
        }

        queue<pair<int,int>> Q;
        int cnt = 0;

        // 아무에게도 선택받지 못한 애들이 시작점.
        for (int i = 1; i <= n; i++) {
            if (choosed[i] == 0) {
                Q.push({i, students[i]});
                choosed[students[i]]--;
                cnt++;
            }
        }

        while (!Q.empty()) {
            pair<int,int> cur = Q.front();    Q.pop();
            int next = cur.second;
            // 다음 친구가 스스로 선택한 친구면 continue;
            if (next == students[next]) continue;
            else if (choosed[next] == 0) {
                Q.push({next, students[next]});
                choosed[students[next]]--;
                cnt++;
            }
        }

        cout << cnt << '\n';

        // choosed 초기화
        fill(choosed, choosed + n + 1, 0);
    }
}