//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int gain = 0, n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    auto l1 = 0, r1 = n - 1, l2 = 0, r2 = n - 1;
    while (l1 <= r1 && l2 <= r2) {
        if (a[r1] > b[r2]) {
            gain += 200;
            r1--;
            r2--;
        } else if (a[r1] < b[r2]) {
            gain -= 200;
            l1++;
            r2--;
        } else {
            if (a[l1] > b[l2]) {
                gain += 200;
                l1++;
                l2++;
            } else if (a[l1] < b[l2]) {
                gain -= 200;
                l1++;
                r2--;
            } else if (a[l1] == b[l2]) {
                if (a[l1] < b[r2]) {
                    gain -= 200;
                }
                l1++;
                r2--;
            }
        }
    }

    cout << gain << endl;
    return 0;
}