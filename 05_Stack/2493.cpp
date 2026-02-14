#include <bits/stdc++.h>
using namespace std;

struct Building {
    int height, index;
};

int main() {

    int N;
    cin >> N;

    vector<int> nums;
    while (N--) {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    stack<Building> st;
    vector<int> result;

    int idx = 0;
    while (idx < nums.size()) {
        int a = nums[idx];

        if (st.empty()) {
            result.push_back(0);
            st.push({a, ++idx});
        } else if (st.top().height > a) {
            result.push_back(st.top().index);
            st.push({a, ++idx});
        } else {
            st.pop();
        }
    }

    for (int j : result) {
        cout << j << ' ';
    }
}