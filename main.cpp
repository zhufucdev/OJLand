//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct pack {
    int price, mass;
    float ratio;

    bool operator<(const pack &p) const {
        return ratio > p.ratio;
    }
};

bool solve() {
    int n, t;
    if (!(cin >> n >> t)) {
        return false;
    }
    pack packs[n];
    for (int i = 0; i < n; ++i) {
        cin >> packs[i].mass >> packs[i].price;
        packs[i].ratio = packs[i].price * 1.0f / packs[i].mass;
    }
    sort(packs, packs + n);

    float value = 0;
    for (int i = 0; i < n; ++i) {
        if (packs[i].mass < t) {
            t -= packs[i].mass;
            value += packs[i].price;
        } else {
            value += packs[i].ratio * t;
            break;
        }
    }

    cout << (int) value;

    return true;
}

int main() {
    while (solve()) {
        cout << endl;
    }
    return 0;
}