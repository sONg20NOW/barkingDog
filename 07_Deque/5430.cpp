#include <bits/stdc++.h>
using namespace std;

void CheckDeque(deque<int> DQ) {
    cout << "Check!" << '\n';

    for (int i : DQ) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        string p;
        cin >> p;
        
        int n;
        cin >> n;

        string s;
        cin >> s;
        deque<int> DQ;

        string number = "";
        for (char c : s) {
            switch(c) {
                case '[':
                    break;
                case ']':
                case ',':
                    if (number != "") {
                        DQ.push_back(stoi(number));
                        number = "";
                    }
                    break;
                default:
                    number.push_back(c);
                    break;
            }
        }
        
        // CheckDeque(DQ);

        bool reverse = false;
        bool error = false;

        for (char c : p) {
            switch(c) {
                case 'R':
                    reverse = !reverse;
                    break;
                case 'D':
                    if (DQ.empty()) {
                        error = true;
                        break;
                    } 

                    if (reverse) {
                        DQ.pop_back();
                    } else {
                        DQ.pop_front();
                    }
                    break;
                default: 
                    break;
            }

            if(error)   break;
        }

        // CheckDeque(DQ);

        if (error)  cout << "error" << '\n';
        else {
            cout << '[';
            while (!DQ.empty()) {
                if (reverse) {
                    cout << DQ.back();
                    DQ.pop_back();
                } else {
                    cout << DQ.front();
                    DQ.pop_front();
                }
  
                if (!DQ.empty()) {
                    cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }
    
}