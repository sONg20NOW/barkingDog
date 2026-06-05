#include <bits/stdc++.h>
using namespace std;

int T;
int n;
const int MX = 12;
int D[MX];

int main() {
    cin >> T;
    D[0] = 1;
    while (T--) {
        cin >> n;
        if (D[n] > 0) {
            cout << D[n] << '\n';
            continue;
        }

        for (int i = 1; i <= n; i++) {
            if (D[i] > 0)   continue;
            D[i] += (i-1 >= 0 ? D[i-1] : 0);
            D[i] += (i-2 >= 0 ? D[i-2] : 0);
            D[i] += (i-3 >= 0 ? D[i-3] : 0);
        }

        cout << D[n] << '\n'; 
    }
}