#include <bits/stdc++.h>
using namespace std;

string gears[4];
int gear_peek[4];
int K;
int target, cmd;

struct Gear {
    char left, right;
};

// g번째 gear의 왼쪽/오른쪽 NS 값을 리턴
Gear peekToRL(int g) {
    int peek = gear_peek[g];
    char rightNS = gears[g][(peek + 2) % 8];
    char leftNS = gears[g][(peek - 2 + 8) % 8];
    return {leftNS, rightNS};
}

// g번째 gear의 오른쪽/왼쪽이 회전해야 하는지 여부를 bool값으로 반환
// left: 0, right: 1
bool shouldWave(int g, int right) {
    Gear cur_NS = peekToRL(g);
    if (right) {
        if (g + 1 >= 4) return false;
        Gear right_NS = peekToRL(g + 1);
        if (right_NS.left != cur_NS.right)   return true;
    } else {
        if (g - 1 < 0)  return false;
        Gear left_NS = peekToRL(g - 1);
        if (left_NS.right != cur_NS.left)   return true;
    }
    return false;
}

// g번째 gear를 dir 방향으로 회전
void rotate(int g, int dir) {
    bool waveLeft = shouldWave(g, 0);
    bool waveRight = shouldWave(g, 1);

    if (dir == 1) {
        gear_peek[g] = (gear_peek[g] - 1 + 8) % 8;
    } else {
        gear_peek[g] = (gear_peek[g] + 1) % 8;
    }

    // cout << "rotate " << g << " to direction: " << dir <<", peek: " << gear_peek[g] << '\n';
    // for (int i = 0; i < 4; i++) {
    //     cout << "gear " << i << ": " << gear_peek[i] << " - ";
    // }
    // cout << '\n';
    // cout << "should wave right: " << (waveRight ? "yes" : "no") << " / should wave left: " << (waveLeft ? "yes" : "no") << '\n';

    if (target == g) {
        if (waveLeft)   rotate(g - 1, -dir);
        if (waveRight)   rotate(g + 1, -dir);
    } else if (target < g) {
        if (waveRight)   rotate(g + 1, -dir);
    } else {
        if (waveLeft)   rotate(g - 1, -dir);
    }

}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> gears[i];
    }

    cin >> K;
    while(K--) {
        cin >> target >> cmd;
        target--;
        rotate(target, cmd);
    }

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += (1 << i) * (gears[i][gear_peek[i]] - '0');
    }

    cout << sum;
}