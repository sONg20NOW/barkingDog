#include <bits/stdc++.h>
using namespace std;

int K = 0;
vector<string> answer;

void func(int a, int b, int n) {
    stringstream ss;
    if (n == 1) {
        ss << a << ' ' << b << '\n';
        answer.push_back(ss.str());
        K++;
        return;
    }
    // 1 ~ N-1을 a에서 6-a-b로 옮기기
    func(a, 6-a-b, n-1);
    // N을 a에서 b로 옮기기
    ss << a << ' ' << b << '\n';
    answer.push_back(ss.str());
    K++;
    // 1 ~ N-1을 6-a-b에서 b로 옮기기
    func(6-a-b, b, n-1);
}

int main() {
    int N;
    cin >> N;
    func(1, 3, N);

    cout << K << '\n';
    for (string s : answer) {
        cout << s;
    }
}