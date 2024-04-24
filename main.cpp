//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <algorithm>

using namespace std;

void arr(int n, int d, int k[]) {
    if (d >= n) {
        for (int j = 0; j < d; ++j) {
            cout << k[j];
        }
        cout << "\n";
        return;
    }
    int r[n - d], tmp[d + 1], t = 0, u = 0;
    copy(k, k + d, tmp);
    sort(tmp, tmp + d);
    tmp[d] = 0;
    for (int i = 1; i <= n; ++i) {
        if (d == 0 || tmp[t] != i) {
            r[u++] = i;
        } else {
            t++;
        }
    }
    for (int i = 0; i < n - d; ++i) {
        k[d] = r[i];
        arr(n, d + 1, k);
    }
}

bool solve() {
    int n;
    if (!(cin >> n)) {
        return false;
    }
    auto *tmp = new int[n];
    arr(n, 0, tmp);
    delete[] tmp;
    return true;
}

int main() {
    while (solve()) {
    }
    return 0;
}
