#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
    int pre_addr = addr;
    int nxt_addr = nxt[addr];

    dat[unused] = num; 
    pre[unused] = pre_addr;
    nxt[unused] = nxt_addr;

    nxt[pre_addr] = unused;
    if (nxt_addr >= 0) {
        pre[nxt_addr] = unused;
    }

    unused++;
}

void erase(int addr){
    int pre_addr = pre[addr];
    int nxt_addr = nxt[addr];

    // previous
    nxt[pre_addr] = nxt_addr;

    // next
    if (nxt_addr >= 0)
        pre[nxt_addr] = pre_addr;
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

int main() {
    string s;
    int N;

    cin >> s;
    cin >> N;

    int addr = 0;
    for (char c : s) {
        insert(addr++, c);
    }

    cin.ignore();
    for (int i = 0; i < N; i++) {
        string command;
        getline(cin, command);

        if (command == "L") {
            if (cursor != 0)
                cursor = ;
        } else if (command == "D") {
            if (cursor != --chars.end())
                cursor++;
        } else if (command == "B") {
            if (cursor != chars.begin())
                chars.erase(cursor);
                cursor--;
        } else {
            stringstream ss = stringstream(command);
            char p, c;
            ss >> p >> c;
            if (p == 'P') {

            }
        }
    }

}