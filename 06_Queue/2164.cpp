#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int i = 1;
    queue<int> Q;
    while (N--) {
        Q.push(i++);
    }

    while (Q.size() > 1) {
        Q.pop();
        int top = Q.front();
        Q.pop();
        Q.push(top);
    }

    cout << Q.front() << '\n';
}