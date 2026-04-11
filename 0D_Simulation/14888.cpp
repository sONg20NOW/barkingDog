#include <bits/stdc++.h>
using namespace std;

int N;
int A[12];

int OPT[4];
long long max_res = -1000000000;
long long min_res = 1000000000;

void func(int k, long long res) {
    if (k == N) {
        max_res = max(max_res, res);
        min_res = min(min_res, res);

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (OPT[i] == 0)    continue;
        OPT[i]--;        
        switch (i)
        {
        case 0:
            func(k + 1, res + A[k]);
            break;
        case 1:
            func(k + 1, res - A[k]);
            break;
        case 2:
            func(k + 1, res * A[k]);
            break; 
        case 3:
            func(k + 1, res / A[k]);
            break;
        
        default:
            break;
        }
        OPT[i]++;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> OPT[i];
    }

    func(1, A[0]);

    cout << max_res << '\n' << min_res;
}