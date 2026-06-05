#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1000001;
int D[MX];

int main() {
    cin >> N;
    D[1] = 0;
    int i = 2;
    while (i <= N) {
        D[i] = D[i-1] + 1;
        if (i % 3 == 0) {
            D[i] = min(D[i], D[i / 3] + 1);
        }
        if (i % 2 == 0) {
            D[i] = min(D[i], D[i / 2] + 1);
        }
        i++;
    }

    cout << D[N];
}