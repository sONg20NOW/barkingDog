#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> deq;
    vector<int> result;

    while (N--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int x;
            cin >> x;
            deq.push_front(x);
        } else if (command == "push_back") {
            int x;
            cin >> x;
            deq.push_back(x);
        } else if (command == "pop_front") {
            result.push_back(deq.empty() ? -1 : deq.front());
            if (!deq.empty())
                deq.pop_front();
        } else if (command == "pop_back") {
            result.push_back(deq.empty() ? -1 : deq.back());
            if (!deq.empty())
                deq.pop_back();
        } else if (command == "size") {
            result.push_back(deq.size());
        } else if (command == "empty") {
            result.push_back(deq.empty() ? 1 : 0);
        } else if (command == "front") {
            result.push_back(deq.empty() ? -1 : deq.front());
        } else {
            result.push_back(deq.empty() ? -1 : deq.back());
        }
    }
    for (int r : result) {
        cout << r << '\n';
    }
}