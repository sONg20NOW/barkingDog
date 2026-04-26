#include <bits/stdc++.h>
using namespace std;

int N;
struct EGG {
    int s, w;
};
EGG eggs[10];

void printEggs() {
    for (int i = 0; i < N; i++) {
        cout << eggs[i].s << ' ';
    }
    cout << '\n';
}

int brokenEggs() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (eggs[i].s <= 0)   cnt++;
    }

    return cnt;
}

int max_broken = 0;

void func(int k) {
    // cout << k << "th egg state:" << '\n';
    // printEggs();

    int broken_cnt = brokenEggs();
    if (k == N) {
        max_broken = max(max_broken, broken_cnt);
        return;
    }

    // 현재 계란이 부서져있다면 다음 계란으로
    if (eggs[k].s <= 0 || broken_cnt >= N - 1) {
        func(k + 1);
        return;
    }

    // 현재 계란으로 다음에 칠 계란 찾기
    // 지금 계란을 제외한 모든 계란이 깨져있다면?
    for (int i = 0; i < N; i++) {
        if (i == k) continue;
        if (eggs[i].s <= 0) continue;
        eggs[i].s -= eggs[k].w;
        eggs[k].s -= eggs[i].w;
        func(k + 1);
        eggs[i].s += eggs[k].w;
        eggs[k].s += eggs[i].w;
    }

}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> eggs[i].s >> eggs[i].w;
    }

    func(0);

    cout << max_broken << '\n';
}