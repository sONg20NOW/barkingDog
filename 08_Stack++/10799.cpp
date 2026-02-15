#include <bits/stdc++.h>
using namespace std;

// 스택에 남아있는 애들 -> 잘리는 대상들. 이 수만큼 더 해주면 되는 거 아닌가?
int main() {
    string s;
    cin >> s;

    int count = 0;
    stack<char> ST;

    int idx = 0;
    while (idx < s.size()) {
        char c = s[idx];
        switch (c) {
            case '(':
                if (s[idx + 1] == ')') {
                    // 레이저가 나온 경우
                    count += ST.size();
                    idx++;
                } else {
                    ST.push('(');
                }
                break;
            case ')':
                ST.pop();
                count++;
                break;
            default:
                break;
        }
        idx++;
    }

    cout << count << '\n';
}