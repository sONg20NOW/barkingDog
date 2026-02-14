#include <bits/stdc++.h>
using namespace std;


int where(deque<int> DQ, int x) {
    int idx = 0;
    while (idx < DQ.size()) {
        if (DQ[idx] == x) {
            break;
        }
        idx++;
    }

    return idx;
}

void method_two(deque<int>& DQ, int& count) {
    int a = DQ.front();
    DQ.pop_front();
    DQ.push_back(a);
    count++;
}

void method_three(deque<int>& DQ, int& count) {
    int a = DQ.back();
    DQ.pop_back();
    DQ.push_front(a);
    count++;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> targets;
    int target_cnt = M;
    while(M--) {
        int a;
        cin >> a;
        targets.push_back(a);
    }

    deque<int> DQ;
    int a = 1;
    while(N--) {
        DQ.push_back(a++);
    }

    int count = 0;
    int idx = 0;
    while (idx < target_cnt) {
        int target = targets[idx];
        if (DQ.front() != target) {
            if (where(DQ, target) - 1 < DQ.size() - where(DQ, target)) {
                // 2번으로 진행하는 게 타겟에 더 가까움
                while (DQ.front() != target) {
                    method_two(DQ, count);
                }
            } else {
                while (DQ.front() != target) {
                    method_three(DQ, count);
                }
            }
        }
        DQ.pop_front();
        idx++;

    }

    cout << count;
}
