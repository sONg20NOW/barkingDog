#include <bits/stdc++.h>
using namespace std;

int L, C;
char candits[15];
char arr[15];
int jaeum_cnt, moeum_cnt;
char moeums[5] = {'a', 'e', 'i', 'o', 'u'};

void func(int k, int last_idx) {
    if (k == L) {
        if (jaeum_cnt < 2 || moeum_cnt < 1) return;
        // cout << "J: " << jaeum_cnt << ", M: " << moeum_cnt << '\n';
        for (int i = 0; i < L; i++) {
            cout << arr[i];
        }
        cout << '\n';
        return;
    }

    for (int i = last_idx + 1; i < C; i++) {
        char c = candits[i];
        arr[k] = c;
        if (find(moeums, moeums + 5, c) != moeums + 5) {
            moeum_cnt++;
            func(k + 1, i);
            moeum_cnt--;
        } else {
            jaeum_cnt++;
            func(k + 1, i);
            jaeum_cnt--;
        }
    }
}

int main() { 

    cin >> L >> C;
    
    for (int i = 0; i < C; i++) {
        cin >> candits[i];
    }

    sort(candits, candits + C);

    func(0, -1);

}