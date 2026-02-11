#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> s;

    while(N--) {
        string command;
        cin >> command;

        if (command == "push") {
            int X;
            cin >> X;
            s.push(X);
        }
        else if (command == "pop") {
            if (s.empty()) {
                cout << "-1" << '\n';
            }
            else {
                int K = s.top();
                s.pop();
                cout << K << '\n';
            }
        } else if (command == "size") {
            cout << s.size() << '\n';
        } else if (command == "empty") {
            cout << (s.empty() ? 1 : 0) << '\n';
        } else {
            if (s.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << s.top() << '\n';
            }
        }
    }
}