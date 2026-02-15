#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    while (N--) {
        string s;
        cin >> s;
        
        stack<char> ST;
        for (char c : s) {
            if (ST.empty() || ST.top() != c) {
                ST.push(c);
            } else {
                ST.pop();
            } 
        }
        if (ST.empty()) count++;
    }

    cout << count << '\n';
}