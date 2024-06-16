//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>

using namespace std;

int main() {
    int m, s, t, travel = 0, teleport = 0;
    cin >> m >> s >> t;
    for (int i = 1; i <= t; i++) {
        travel += 17;
        if (m >= 10) {
            m -= 10;
            teleport += 60;
        } else {
            m += 4;
        }
        travel = max(travel, teleport);
        if (travel >= s) {
            cout << "Yes" << endl << i;
            return 0;
        }
    }
    cout << "No" << endl << travel;
    return 0;
}