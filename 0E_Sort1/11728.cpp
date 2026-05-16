#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MX = 1000001;
queue<int> A;
queue<int> B;
queue<int> result;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push(a);
    }
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        B.push(b);    
    }

    while (!A.empty() && !B.empty()) {
        int a = A.front();   int b = B.front();
        if (a < b) {
            A.pop();
            result.push(a);
        } else {
            B.pop();
            result.push(b);
        }
    }
    while (!A.empty()) {
        int t = A.front(); A.pop();
        result.push(t);
    }
    while (!B.empty()) {
        int t = B.front(); B.pop();
        result.push(t);
    }

    while (!result.empty()) {
        int t = result.front(); result.pop();
        cout << t << ' ';
    }
    return 0;
}