#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 100001;
const int POW_MX = 400;
int D[MX];


int main() {
    cin >> N;

    D[0] = 0;
    D[1] = 1;

    for (int i = 2; i <= MX; i++) {
        // D[i] 구하기
        D[i] = D[i-1] + 1;
        for (int j = 2; j*j <= i; j++) {
            D[i] = min(D[i], D[i-j*j] + 1);
        }
    }

    cout << D[N];
}