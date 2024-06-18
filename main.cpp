//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>

using namespace std;

bool not_bad(int64_t n) {
    int64_t a;
    while (n != 0) {
        a = n % 10;
        n = n / 10;
        if (a == 4) {
            return false;
        }
        if (a == 2) {
            a = n % 10;
            if (a == 6) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int64_t l, r;
    cin >> l >> r;

    while (l != 0 && r != 0) {
        int count = 0;

        for (auto i = l; i <= r; i++) {
            if (not_bad(i))
                count++;
        }

        cout << count << endl;
        cin >> l >> r;
    }
    return 0;
}