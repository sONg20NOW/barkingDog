#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MX = 100001;

int N;
pair<int,int> arr[MX];
pair<int,int> tmp[MX];

bool isX = true;

void merge(int st, int en) {
    int mid = (en + st) / 2;

    int l = st;
    int r = mid;

    int idx = 0;

    while (l < mid || r < en) {
        int lv = isX ? arr[l].X : arr[l].Y;
        int rv = isX ? arr[r].X : arr[r].Y;
        if (l == mid) {
            tmp[idx++] = arr[r++];
        } else if (r == en) {
            tmp[idx++] = arr[l++];
        } else if (lv <= rv) {
            tmp[idx++] = arr[l++];
        } else {
            tmp[idx++] = arr[r++];
        }
    }

    for (int i = 0; i < idx; i++) {
        arr[st + i] = tmp[i];
    }
}

void merge_sort(int st, int en) {
    if (en - st == 1)   return;
    int mid = (en + st) / 2;
    
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].X >> arr[i].Y;
    }

    merge_sort(0, N);
    isX = false;
    merge_sort(0, N);

    for (int i = 0; i < N; i++) {
        cout << arr[i].X << ' ' << arr[i].Y << '\n';
    }
}
