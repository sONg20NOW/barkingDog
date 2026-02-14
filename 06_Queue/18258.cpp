#include <bits/stdc++.h>
using namespace std;

const int MX = 2000001;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
  dat[tail++] = x;
}

void pop(){
  if (head != tail)
    head++;
}

int front(){
  return dat[head];
}

int back(){
  return tail > 0 ? dat[tail - 1] : -1;
}

int main() {
    int N;
    cin >> N;

    vector<int> result;
    while(N--) {
        string command;
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (command == "pop") {
            if (head - tail == 0) {
                result.push_back(-1);
            } else {
                result.push_back(front());
                pop();
            }
        } else if (command == "size") {
            result.push_back(tail - head);
        } else if (command == "empty") {
            result.push_back(tail - head == 0 ? 1 : 0);
        } else if (command == "front") {
            result.push_back(tail - head == 0 ? -1 : dat[head]);
        } else {
            result.push_back(tail - head == 0 ? -1 : dat[tail - 1]);
        }
    }

    for (int i : result) {
        cout << i << '\n';
    }
}