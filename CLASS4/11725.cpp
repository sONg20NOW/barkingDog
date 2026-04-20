#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100001];
int visited[100001];
int parent[100001];
queue<int> Q;

int N;

void func() {
    Q.push(1);
    visited[1] = 1;
    parent[1] = -1;

    while(!Q.empty()) {
        int cur = Q.front();  Q.pop();
        for (int next : tree[cur]) {
            if (visited[next])    continue;
            parent[next] = cur;
            visited[next] = 1;
            Q.push(next);
        }
    }
}

int main() {
    cin >> N;
    int temp = N - 1;
    while (temp--) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    func();

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
}