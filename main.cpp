//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct game {
    int ddl, cost;

    bool operator<(const game &g) const {
        return cost > g.cost;
    }
};

bool solve() {
    int m, n;
    if (!(cin >> m >> n)) {
        return false;
    }
    game games[n];
    bool occupied[n];
    for (int i = 0; i < n; ++i) {
        cin >> games[i].ddl;
        occupied[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        cin >> games[i].cost;
    }
    sort(games, games + n);
    for (int i = 0; i < n; ++i) {
        bool taken = false;
        for (int t = games[i].ddl - 1; t >= 0; --t) {
            if (!occupied[t]) {
                occupied[t] = true;
                taken = true;
                break;
            }
        }
        if (!taken) {
            m -= games[i].cost;
        }
    }
    cout << m;
    return true;
}

int main() {
    while (solve()) {
        cout << endl;
    }
    return 0;
}