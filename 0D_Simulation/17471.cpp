#include <bits/stdc++.h>
using namespace std;

int N;
int people[11];
int all_sum;
vector<int> adjs[11];

int A_size = 0;
int arr[11];

const int MX = 1 << 13;
int min_diff = MX;

// 나눈 구역이 제대로 나눈 것인지 확인 (BFS를 했을 때 visited가 안된 곳이 남아있으면 안됨)
int isPossible() {
    int A_sum = 0;

    int visited[11];
    fill(visited, visited + 11, 0);

    // 시작점 넣기
    int start_point;
    for (int i = 0; i < N; i++) {
        if (arr[i]) {
            start_point = i;
            break;
        }
    }

    queue<int> Q;
    Q.push(start_point);
    visited[start_point] = 1;
    A_sum += people[start_point];
    while(!Q.empty()) {
        int cur = Q.front();    Q.pop();
        for (int adj_part : adjs[cur]) {
            if (visited[adj_part] || !arr[adj_part])  continue;
            Q.push(adj_part);
            visited[adj_part] = 1;
            A_sum += people[adj_part];
        }
    }

    // arr[i] = 1인데 visited[i] = 0인 애가 있는지 확인
    for (int i = 0; i < N; i++) {
        if (arr[i] && !visited[i])  return -1;
    }

    // 반대편 애들도 연결 되어있는지 확인
    fill(visited, visited + 11, 0);
    for (int i = 0; i < N; i++) {
        if (!arr[i]) {
            start_point = i;
            break;
        }
    }

    Q.push(start_point);
    visited[start_point] = 1;
    while(!Q.empty()) {
        int cur = Q.front();    Q.pop();
        for (int adj_part : adjs[cur]) {
            if (visited[adj_part] || arr[adj_part])  continue;
            Q.push(adj_part);
            visited[adj_part] = 1;
        }
    }

    // arr[i] = 1인데 visited[i] = 0인 애가 있는지 확인
    for (int i = 0; i < N; i++) {
        if (!arr[i] && !visited[i])  return -1;
    }

    return abs((all_sum - A_sum) - A_sum);
}

// 1 ~ N 중에 A_size만큼 뽑기
void func(int k, int last_idx = -1) {
    if (k == A_size) {
        int res = isPossible();
        if (res >= 0) {
            min_diff = min(min_diff, res);
        }

        return;
    }

    for (int i = last_idx + 1; i < N; i++) {
        arr[i] = 1;
        func(k + 1, i);
        arr[i] = 0;
    }
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> people[i];
        all_sum += people[i];
    }

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            adjs[i].push_back(a - 1);
        }
    }

    while (A_size++ < N) {
        func(0);
    }

    cout << (min_diff == MX ? -1 : min_diff) << '\n';
}