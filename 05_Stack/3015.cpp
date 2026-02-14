#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    long long count = 0;

    vector<int> line;
    stack<pair<int, int>> st;
    while (N--) {
        int n;
        cin >> n;
        line.push_back(n);
    }

    int idx = 0;
    while(idx < line.size()) {
        int a = line[idx];

        if (st.empty()) {
            st.push({a, 1});
            idx++;
        } 
        // 나보다 작은 애들 정리 -> 얘네는 나 때문에 가려지니까 더 이상 스택에 남을 이유가 없음.
        else if (st.top().first < a) {
            count += st.top().second;
            st.pop();
        } 
        // 나랑 같은 애들 -> 키가 같은 애들 다 볼 수 있고, 그 다음에 키 큰 사람이 있다면 그 사람까지 볼 수 있음.
        else if (st.top().first == a) {
            count += st.top().second++;
            if (st.size() > 1) {
                count++;
            }
            idx++;
        }
        // 나보다 큰 애들 -> 나보다 큰 애 한명만 볼 수 있음.
         else {
            count++;
            st.push({a, 1});
            idx++;
        }

    }

    cout << count;
    
}