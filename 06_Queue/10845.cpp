#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    queue<int> q;
    vector<int> result;
    while (N--) {
        string command;
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if (command == "pop") {
            if (q.empty()) {
                result.push_back(-1);
            } else {
                result.push_back(q.front());
                q.pop();
            }
        } else if (command == "size") {
            result.push_back(q.size());
        } else if (command == "empty") {
            result.push_back(q.empty() ? 1 : 0);
        } else if (command == "front") {
            if (q.empty()) {
                result.push_back(-1);
            } else {
                result.push_back(q.front());
            }
        } else {
            if (q.empty()) {
                result.push_back(-1);
            } else {
                result.push_back(q.back());
            }
        }
    }

    for (int i : result) {
        cout << i << '\n';
    }
}