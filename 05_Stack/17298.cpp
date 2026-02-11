#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    stringstream ss;
    stack<int> A;
    stack<int> rest;
    stack<int> result;

    while(N--) {
        int n;
        cin >> n;
        A.push(n);
    }


    while(!A.empty()) {
        int a = A.top();
        if (rest.empty()) {
            result.push(-1);
            rest.push(a);
            A.pop(); 
        } else {
            if (rest.top() > a) {
                result.push(rest.top());
                rest.push(a);
                A.pop();
            } else {
                rest.pop();
            }
        }
    }

    while(!result.empty()) {
        cout << result.top() << ' ';
        result.pop();
    }
}