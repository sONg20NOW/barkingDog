#include <bits/stdc++.h>    
using namespace std;

struct char_and_symbol {
    int value;
    char symbol;
};

int main() {
    string s;
    cin >> s;

    bool impossible = false;
    stack<char> gates;
    stack<pair<int, int>> stacks;
    for (char c : s) {
        switch(c) {
            case '(':
                gates.push('(');
                break;
            case '[':
                gates.push('[');
                break;
            case ')':
                if (gates.empty() || gates.top() != '(') {
                    impossible = true;
                } else {
                    // push 하기 전에 
                    int height = gates.size() - 1;
                    if (stacks.empty() || height > stacks.top().second) {
                        stacks.push({2, height});
                    } else {
                        pair<int, int> temp = {2, height};
                        while (!stacks.empty() &&  temp.second <= stacks.top().second) {
                            if (stacks.top().second == temp.second) {
                                temp.first += stacks.top().first;
                            } else {
                                temp.first *= stacks.top().first;
                            }
                            stacks.pop();
                        }
                        stacks.push(temp);
                    }
                    gates.pop();
                }
                break;
            case ']':
                if (gates.empty() || gates.top() != '[') {
                    impossible = true;
                } else {
                    // push 하기 전에 
                    int height = gates.size() - 1;
                    if (stacks.empty() || height > stacks.top().second) {
                        stacks.push({3, height});
                    } else {
                        pair<int, int> temp = {3, height};
                        while (!stacks.empty() && temp.second <= stacks.top().second) {
                            if (stacks.top().second == temp.second) {
                                temp.first += stacks.top().first;
                            } else {
                                temp.first *= stacks.top().first;
                            }
                            stacks.pop();
                        }
                        stacks.push(temp);
                    }
                    gates.pop();
                }
                break;
        }

        if (impossible) break;
    }

    cout << ((!gates.empty() || impossible) ? 0 : stacks.top().first) << '\n';
}