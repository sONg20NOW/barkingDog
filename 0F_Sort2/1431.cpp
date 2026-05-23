#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 51;
string words[MX];


bool compare(string a, string b) {
    if (a.length() == b.length()) {
        int sum[2] = {0, 0};
        string ss[2] = {a, b};
        for (int i = 0; i < 2; i++) {
            for (char c : ss[i]) {
                if (c >= '0' && c <= '9') {
                    sum[i] += c -'0';
                }
            }
        }

        if (sum[0] == sum[1]) {
            return a < b;
        }

        return sum[0] < sum[1];
    }

    return a.length() < b.length();
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    sort(words, words+N, compare);

    // cout << "---\n";
    for (int i = 0; i < N; i++) {
        cout << words[i] << '\n';
    }
}