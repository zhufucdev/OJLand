//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>

using namespace std;

int main() {
    int n, _max;
    cin >> n;

    int a[n + 1], b[n + 1], c[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        b[i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            if ((a[i] > a[j]) && (b[j] + 1 > b[i])) {
                b[i] = b[j] + 1;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        c[i] = 1;
        for (int j = i; j <= n; j++) {
            if ((a[i] > a[j]) && (c[j] + 1 > c[i])) {
                c[i] = c[j] + 1;
            }
        }
    }
    _max = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] + c[i] > _max) {
            _max = b[i] + c[i];
        }
    }
    cout << n - _max + 1 << endl;
    return 0;
}