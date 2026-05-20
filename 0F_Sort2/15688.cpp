#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1000001;
// -1000000~-1
int neg_freq[MX];
// 0~1000000
int pos_freq[MX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num < 0) {
            neg_freq[abs(num)]++;
        } else {
            pos_freq[num]++;
        }
    }

    for (int i = -1000000; i < 0; i++) {
        while (neg_freq[abs(i)]--) {
            cout << i << '\n';
        }
    }

    for (int i = 0; i <= 1000000; i++) {
        while (pos_freq[i]--) {
            cout << i << '\n';
        }
    }
}