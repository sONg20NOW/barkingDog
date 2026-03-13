#include <bits/stdc++.h>
using namespace std;

int L, C;
char candits[15];
char arr[15];
int jaeum_cnt, moeum_cnt;

void func(int k, int last_idx) {
    if (k == L) {
        for (int i = 0; i < L; i++) {
            cout << arr[i];
        }
        cout << '\n';
        return;
    }

    for (int i = last_idx + 1; i < C; i++) {
        
    }
}

int main() { 

    cin >> L >> C;
    
    for (int i = 0; i < C; i++) {
        cin >> candits[i];
    }

    sort(candits, candits + C);

}