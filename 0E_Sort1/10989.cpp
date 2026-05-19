#include <bits/stdc++.h>
using namespace std;

const int MX = 10000001;
int N;
int num[MX];
int temp[MX];

void merge(int st, int en) {
    int mid = (st + en) / 2;

    int l = st;
    int r = mid;

    int idx = 0;
    while (l < mid || r < en) {
        if (l == mid) {
            temp[idx++] = num[r++];
        }  else if (r == en) {
            temp[idx++] = num[l++];
        } else if (num[l] <= num[r]) {
            temp[idx++] = num[l++];
        } else {
            temp[idx++] = num[r++];
        }
    }

    for (int i = 0; i < idx; i++) {
        num[st + i] = temp[i];
    }
}

void merge_sort(int st, int en) {
    if (en - st == 1)   return;
    
    int mid = (st + en) / 2;

    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    merge_sort(0, N);

    for (int i = 0; i < N; i++) {
        cout << num[i] << '\n';
    }
}