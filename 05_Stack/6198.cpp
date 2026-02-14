#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> h;
    while(N--) {
        int height;
        cin >> height;

        h.push_back(height);
    }

    long long count = 0;

    stack<pair<int, int>> st;
    int idx = h.size() - 1;
    while(idx >= 0) {
        int a = h[idx];

        if (st.empty()) {
            st.push({a, 0});
        } else if (st.top().first >= a) {
            st.push({a, 0});
        } else {
            pair<int,int> cur = {a, 0};
            while (st.top().first < a) {
                cur.second += st.top().second + 1;
                st.pop();
                if (st.empty()) break;
            }
            st.push(cur);
            count += cur.second;
        }
        idx--;

    }

    cout << count;
}