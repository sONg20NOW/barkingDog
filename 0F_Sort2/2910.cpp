#include <bits/stdc++.h>
using namespace std;

int N;
long long C;
const int MX = 1001;
long long arr[MX];
// 출현 빈도
map<long long, int> freq;
// 나온 순서
map<long long, int> out;

bool compare(long long a, long long b) {
    if (freq[a] == freq[b]) {
        return out[a] < out[b];
    }
    return freq[a] > freq[b];
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (freq[arr[i]] == 0) {
            out[arr[i]] = i;
        }
        freq[arr[i]]++;
    }

    sort(arr, arr+N, compare);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
}