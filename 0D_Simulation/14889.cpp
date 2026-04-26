#include <bits/stdc++.h>
using namespace std;

int N;
int S[21][21];
int min_diff = 200 * 10 - 20;

int arr[21];
// N명 중에 N/2명 뽑기.

void func(int k, int last_idx = -1) {
    if (k == N/2) {
        int teamA = 0;
        int teamB = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i] == arr[j]) {
                    if (arr[i] == 1) 
                        teamA += S[i][j];
                    else
                        teamB += S[i][j];
                } 
            }
        }
        
        min_diff = min(min_diff, abs(teamA - teamB));
        return;
    }

    for (int i = last_idx + 1; i < N; i++) {
        if (arr[i]) continue;
        arr[i] = 1;
        func(k + 1, i);
        arr[i] = 0;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    func(0);
    cout << min_diff << '\n';
}