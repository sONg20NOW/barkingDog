#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 100001;
int arr[MX];
int temp[MX];

// [st:mid]와 [mid:end]가 모두 내림차순 정렬되어 있다고 가정.
void merge(int st, int end) {
    int mid = (end + st) / 2;
    int l = st;
    int r = mid;
    int idx = 0;

    while (l < mid || r < end) {
        if (l == mid) {
            temp[idx++] = arr[r++];
        } else if (r == end) {
            temp[idx++] = arr[l++];
        } else if(arr[l] >= arr[r]) {
            temp[idx++] = arr[l++];
        } else {
            temp[idx++] = arr[r++];
        }
    }

    for (int i = 0; i < idx; i++) {
        arr[st + i] = temp[i];
    }
}

void merge_sort(int st, int end) {
    if (end - st == 1)  return;
    int mid = (end + st) / 2;
    merge_sort(st, mid);
    merge_sort(mid, end);
    merge(st, end);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    merge_sort(0, N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
}