#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;
    stack<int> s;

    while(K--) {
        int n;
        cin >> n;
        if (n == 0) {
            s.pop();
        }
        else {
            s.push(n);
        }
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum;
}