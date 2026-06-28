#include <bits/stdc++.h>
using namespace std;

int code;
const int MOD = 1000000;
const int MX = 5001;
int D[MX];

// k-1, k번 두 자리 수를 구하는 함수
int getTwoNum(int k, int sz) {
    int t = sz - k;
    int t_code = code;
    while(t--) {
        t_code /= 10;
    }

    return t_code % 100;
}

int main() {
    cin >> code;

    stringstream ss;
    ss << code;
    string codeStr = ss.str();
    int codeSz = codeStr.length();
    D[1] = 1;
    D[2] = 1;
    int  t = getTwoNum(2, codeSz);
    // 10에 대한 예외 처리 추가
    if (t <= 26 && t != 10) {
        D[2] = 2;
    }
    
    for (int k = 3; k <= codeSz; k++) {
        int twoNum = getTwoNum(k, codeSz);
        // 0에 대한 예외 처리 추가
        D[k] = (twoNum % 10 > 0 ? D[k-1] : 0) + (twoNum <= 26 ? D[k-2] : 0);
    }

    cout << D[codeSz];
}