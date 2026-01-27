#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    list<char> chars;
    for (char c : s) {
        chars.push_back(c);
    }

    int N;
    cin >> N;

    list<char>::iterator cursor = chars.end();

    while (N--) {
        char command;
        cin >> command;

        // cout << "command is " << command << '\n';
        switch (command)
        {
        case 'L':
            if (cursor != chars.begin()) 
                cursor--;
            break;
        case 'D':
            if (cursor != chars.end()) 
                cursor++;
            break;
        case 'B':
            if (cursor != chars.begin()) {
                cursor = chars.erase(--cursor);
                cout << "you pressed B" << '\n';
            }
            break;
        case 'P':
            char c;
            cin >> c;

            chars.insert(cursor, c);
            break;
        default:
            break;
        }

        for (char c : chars) {
            cout << c;
        }
        cout << '\n';
    }

    for (char c : chars) {
        cout << c;
    }
}