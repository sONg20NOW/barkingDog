#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> count_arr(26);
    string s;
    cin >> s;

    for (char c : s) {
        count_arr[c - 'a'] += 1;
    }

    for (int count : count_arr) {
        cout << count << ' ';
    }
}