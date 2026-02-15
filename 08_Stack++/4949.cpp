#include <bits/stdc++.h>
using namespace std;

int main() {
    while(true) {
        string s;
        getline(cin, s);

        if (s == ".") {
            break;
        }

        stack<char> st;
        bool yn = true;
        for (char c : s) {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    yn = false;
                    break;
                } else {
                    st.pop();
                }
            } else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    yn = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if (!st.empty())    yn = false;

        if (yn) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
}