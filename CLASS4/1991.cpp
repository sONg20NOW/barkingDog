#include <bits/stdc++.h>
using namespace std;

int N;
struct NODE {
    char self, left, right;
};
NODE tree[27];

// 전위순회
stringstream front_ss;
void front_Look(char c) {
    NODE node = tree[c - 'A'];
    front_ss << c;
    if (node.left != '.') {
        front_Look(node.left);
    }
    if (node.right != '.') {
        front_Look(node.right);
    }
}

// 중위 순회
stringstream mid_ss;
void mid_Look(char c) {
    NODE node = tree[c - 'A'];
    if (node.left != '.') {
        mid_Look(node.left);
    }
    mid_ss << c;
    if (node.right != '.') {
        mid_Look(node.right);
    }
}

// 후위순회
stringstream back_ss;
void back_Look(char c) {
    NODE node = tree[c - 'A'];
    if (node.left != '.') {
        back_Look(node.left);
    }
    if (node.right != '.') {
        back_Look(node.right);
    }
    back_ss << c;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char self, left, right;
        cin >> self >> left >> right;
        tree[self - 'A'] = {self, left, right};
    }
    front_Look('A');
    cout << front_ss.str() << '\n';

    mid_Look('A');
    cout << mid_ss.str() << '\n';

    back_Look('A');
    cout << back_ss.str() << '\n';
}