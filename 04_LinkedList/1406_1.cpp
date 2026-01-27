#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int N;
    cin >> s;
    cin >> N;

    // cout << "s is " << s << " and N is " << N << '\n';

    list<char> chars;

    chars.push_front('$');
    for (char c : s) {
        chars.push_back(c);
    }

    list<char>::iterator cursor = chars.end();
    cursor--;

    cin.ignore();

    for (int i = 0; i < N; i++) {
        string command;
        getline(cin, command);

        // cout << "command is " << command << '\n';

        if (command == "L") {
            if (cursor != chars.begin()) 
                cursor--;
        } else if (command == "D") {
            if (cursor != --chars.end()) 
                cursor++;
        } else if (command == "B") {
            if (cursor != chars.begin()) 
                chars.erase(cursor--);

        } else {
            char a = command[0];
            char b = command[2];

            if (a == 'P') {
                chars.insert(++cursor, b);
                cursor--;
            }
        }

    }

    int flag = 0;
    for (char t : chars) {
        if (flag++ != 0) 
            cout << t;
    }
}