#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int K, E, M;
};

const int MX = 100001;
int N;
Student stds[MX];

bool compare(Student a, Student b) {
    if (a.K == b.K) {
        if (a.E == b.E) {
            if (a.M == b.M) {
                return a.name < b.name;
            }

            return a.M > b.M;
        }

        return a.E < b.E;
    }
    return a.K > b.K;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name;
        int K, E, M;
        cin >> name >> K >> E >> M;
        stds[i] = {name, K, E, M};
    }

    sort(stds, stds+N, compare);

    for (int i = 0; i < N; i++) {
        cout << stds[i].name << '\n';
    }
}