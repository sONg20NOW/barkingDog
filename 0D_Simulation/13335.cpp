#include <bits/stdc++.h>
using namespace std;

struct Truck {
    int idx, entered_t;
};

int truck_cnt, length, max_w;
int trucks[1000];
queue<Truck> bridge;
int on_bridge_w = 0;
queue<int> wait;

int t = 1;

int main() {

    cin >> truck_cnt >> length >> max_w;
    for (int i = 0; i < truck_cnt; i++) {
        cin >> trucks[i];
        wait.push(i);
    }

    while(!wait.empty()) {
        int next_idx = wait.front();
        if (on_bridge_w + trucks[next_idx] <= max_w) {
            // cout << "bridge enetered at " << t << ", truck " << next_idx << '\n';
            bridge.push({next_idx, t});
            on_bridge_w += trucks[next_idx];
            wait.pop();
            t++;
        } else {
            t = bridge.front().entered_t + length;
            on_bridge_w -= trucks[bridge.front().idx];
            bridge.pop();
        }

        while(!bridge.empty() && (t - bridge.front().entered_t >= length)) {
            on_bridge_w -= trucks[bridge.front().idx];
            bridge.pop();
        }
    }

    if(!bridge.empty()) {
        t = length + bridge.back().entered_t;
    }

    cout << t << '\n';

}