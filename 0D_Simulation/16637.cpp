#include <bits/stdc++.h>
using namespace std;

int N;
char given[21];
char ops[10];   // 연산자 최대 9개
int nums[11];  // 숫자 최대 10개
int op_N;
int num_N;

int max_res = -1 << 31;

int op_cnt;
// 우선 계산해야 할 ops의 위치. 개수는 op_cnt개.
int arr[10];

void calculate() {
    deque<int> Q_num;
    queue<char> Q_op;
    Q_num.push_back(nums[0]);
    for (int i = 0; i < op_N; i++) {
        // 우선 계산해야 함.
        if (arr[i]) {
            int target = Q_num.back();  Q_num.pop_back();
            switch (ops[i])
            {
            case '*':
                target *= nums[i + 1];
                break;
            case '+':
                target += nums[i + 1];
                break;
            case '-':
                target -= nums[i + 1];
                break;
            
            default:
                break;
            }
            Q_num.push_back(target);
        } else {
            Q_op.push(ops[i]);
            Q_num.push_back(nums[i + 1]);
        }
    }

    // 실제 계산
    int sum = Q_num.front();    Q_num.pop_front();
    while (!Q_op.empty()) {
        char op = Q_op.front(); Q_op.pop();
        int target = Q_num.front(); Q_num.pop_front();
        switch (op)
        {
        case '*':
            sum *= target;
            break;
        case '+':
            sum += target;
            break;
        case '-':
            sum -= target;
            break;
        
        default:
            break;
        }
    }

    max_res = max(max_res, sum);
}

// 연산자 중에 op_cnt개 선택(선택한 거 다음 거는 선택X) -> 계산해보기
void func(int k, int last_idx = -2) {
    if (k == op_cnt) {
        // cout << "op_cnt: " << op_cnt << '\n';
        // for (int i = 0; i < op_N; i++) {
        //     cout << arr[i] << ' ';
        // }
        // cout << '\n';
        calculate();
        return;
    }

    for (int i = last_idx + 2; i < op_N; i++) {
        if (i >= op_N)  break;
        arr[i] = 1;
        func(k + 1, i);
        arr[i] = 0;
    }
}

int main() {
    cin >> N;
    op_N = N / 2;
    num_N = N / 2 + 1;

    cin >> given;

    for (int i = 0; i < N; i++) {
        char c = given[i];
        if (i % 2 == 0) {
            nums[i / 2] = c - '0';
        } else {
            ops[i / 2] = c;
        }
    }

    while (op_cnt <= (op_N + 1) / 2) {
        func(0);
        op_cnt++;
    }

    cout << max_res;
}