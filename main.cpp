//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n)) {
        return false;
    }
    int v = 0, max = 0, t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        v += t;
        if (v < 0) {
            v = 0;
        }
        if (v > max) {
            max = v;
        }
    }
    cout << max;
    return true;
}

int main() {
    while (solve()) {
        cout << "\n";
    }
    return 0;
}