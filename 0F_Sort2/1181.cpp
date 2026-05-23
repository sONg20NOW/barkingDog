#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 20001;
string words[MX];

bool compare(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }

    return a.length() < b.length();
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    sort(words, words + N, compare);

    string prev = "";
    for (int i = 0; i < N; i++) {
        string cur = words[i];
        if (cur != prev) {
            cout << cur << '\n';
            prev = cur;
        }
    }
}