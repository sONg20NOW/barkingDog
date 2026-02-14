#include <bits/stdc++.h>
using namespace std;

// deque 에 추가할 때 추가된 시점(index)도 같이 저장.
// 추가된 시점과 현재 시점의 차이가 L 이상이면 탈락. (탈락은 맨 처음에 진행)
// deque에 추가할 때 만약 추가되는 애가 현재 최소보다 작거나 같다면 deque를 모두 비운다.
struct with_index {
    int value, index;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> A;
    while (N--) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    vector<int> result;
    int idx = 0;
    deque<with_index> DQ;

    while(idx < A.size()) {
        // 시간이 지난 애들 탈락시키기
        while (!DQ.empty() && (idx - DQ.front().index >= L )) {
            DQ.pop_front();
        }
        // 추가 시에 '나'보다 크거나 같은 애들 탈락시키기
        int cur_value = A[idx];
        if (DQ.empty()) {
            DQ.push_back({cur_value, idx});
        } else if (DQ.back().value >= cur_value) {
            while (!DQ.empty() && DQ.back().value >= cur_value) {
                DQ.pop_back();
            }
            DQ.push_back({cur_value, idx});
        } else {
            DQ.push_back({cur_value, idx});
        }
        result.push_back(DQ.front().value);
        idx++;
    }

    for (int r : result) {
        cout << r << ' ';
    }
}