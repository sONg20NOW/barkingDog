#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 301;
int stairs[MX];
// 첫번째 수: 연속해서 1칸
// 두번쨰 수: 연속해서 2칸
pair<int, int> D[301];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }

    D[0] = {0, 0};
    D[1] = {stairs[1], 0};
    for (int i = 2; i <= N; i++) {
        D[i] = {max(D[i-2].first, D[i-2].second) + stairs[i], D[i-1].first + stairs[i]};
    }

    cout << max(D[N].first, D[N].second);
} 