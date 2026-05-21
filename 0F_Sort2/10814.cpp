#include <bits/stdc++.h>
using namespace std;

struct Member {
    int age;
    string name;
};

const int MX = 100001;
int N;
Member mems[MX];

bool compare(Member a, Member b) {
    return a.age < b.age;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        mems[i] = {age, name};
    }

    stable_sort(mems, mems + N, compare);

    for (int i = 0; i < N; i++) {
        cout << mems[i].age << ' ' << mems[i].name << '\n';
    }
}
