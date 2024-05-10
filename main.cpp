//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <iomanip>

using namespace std;

bool solve() {
    int n;
    if (!(cin >> n)) {
        return false;
    }
    int cap[n];
    int max_idx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cap[i];
        if (cap[i] >= cap[max_idx]) {
            max_idx = i;
        }
    }
    int other_cap = 0;
    for (int i = 0; i < n; ++i) {
        if (i == max_idx) continue;
        other_cap += cap[i];
    }
    if (cap[max_idx] > other_cap) {
        cout << fixed << setprecision(1) << other_cap * 1.0;
    } else {
        cout << fixed << setprecision(1) << fixed << (cap[max_idx] + other_cap) * 0.5;
    }

    return true;
}

int main() {
    while (solve()) {
        cout << endl;
    }
    return 0;
}