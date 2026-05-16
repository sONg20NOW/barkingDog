#include <bits/stdc++.h>
using namespace std;

int N;

struct Person {
    int age;
    string name;
};

const int MX = 100001;
Person arr[MX];
Person tmp[MX];

// [st:mid]와 [mid:en]이 모두 정렬되어있을 때 합치는 함수
void merge(int st, int en) {
    int mid = (st + en) / 2;

    int l = st;
    int r = mid;

    int idx = 0;
    while (l < mid || r < en) {
        if (l == mid) {
            tmp[idx++] = arr[r++];
        } else if (r == en) {
            tmp[idx++] = arr[l++];
        } else if (arr[l].age <= arr[r].age) {
            tmp[idx++] = arr[l++]; 
        } else {
            tmp[idx++] = arr[r++]; 
        }
    }
    // arr[i] = tmp[i]; 가 아닌 arr 시작점부터 동작하도록.
    for (int i = 0; i < idx; i++)   arr[st + i] = tmp[i];   
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
        int age;
        string name;
        cin >> age >> name;
        arr[i] = {age, name};
    }
    
    merge_sort(0, N);
    for (int i = 0; i < N; i++) {
        cout << arr[i].age << ' ' << arr[i].name << '\n';
    }
}