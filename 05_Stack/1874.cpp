#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stringstream ss;

    stack<int> st;
    int cur = 1;
    bool possible = true;

    while(n--) {
        int a;
        cin >> a;
        if (st.empty()) {
            while (cur <= a) {
                st.push(cur++);
                ss << '+' << '\n';
            }
            st.pop();
            ss << '-' << '\n';
        } else if (st.top() < a) {
            while (cur <= a) {
                st.push(cur++);
                ss << '+' << '\n';
            }
            st.pop();
            ss << '-' << '\n';
        } else if (st.top() == a) {
            st.pop();
            ss << '-' << '\n';
        }
         else {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << ss.str();
    } else {
        cout << "NO" << '\n';
    }
}