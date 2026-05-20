#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[100001];
int mx_freq;
long long ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    long long prev_n = arr[0];
    int freq = 1;
    for (int i = 1; i < N; i++) {
        long long cur = arr[i];
        if (prev_n == cur) {
            freq++;
        } else {
            if (freq > mx_freq) {
                mx_freq = freq;
                ans = prev_n;
            }
            freq = 1;
        }
        prev_n = cur;
    }

    if (freq > mx_freq) {
        mx_freq = freq;
        ans = prev_n;
    }

    cout << ans;
}