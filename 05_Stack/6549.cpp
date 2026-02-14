#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    long long height, width;

    long long getSize() {
        return this->height * this->width;
    }
};

void UpdateMax(long long& max, long long target) {
    if (max < target) {
        max = target;
    }
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        } 

        vector<int> inp;
        while(n--) {
            int h;
            cin >> h;
            inp.push_back(h);
        }

        long long max_size = 0;
        stack<Rectangle> st;
        int idx = 0;
        while (idx < inp.size()) {
            int a = inp[idx];
            if (st.empty()) {
                st.push({a, 1});
            } else if (st.top().height < a) {
                st.push({a, 1});
            } else {
                long long acc_width = 0;
                
                while(!st.empty() && st.top().height >= a) {
                    st.top().width += acc_width;
                    UpdateMax(max_size, st.top().getSize());
                    acc_width = st.top().width;
                    st.pop();
                }

                st.push({a, acc_width + 1});

            }
            idx++;
        }

        while (!st.empty()) {
            Rectangle prev_top = st.top();
            UpdateMax(max_size, prev_top.getSize());
            st.pop();
            if (!st.empty())    st.top().width += prev_top.width;
        }

        cout << max_size << '\n';
    }
    
}