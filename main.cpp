//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>

using namespace std;

#define value_at(x, y) x >= 0 && x < n && y >= 0 && y < n && map[y][x] != 'W' ? dp[y][x] : 0

bool has_solution(int m, int n) {
    string map[m];
    auto **dp = new int *[m];
    for (int i = 0; i < m; ++i) {
        dp[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 0;
        }
        cin >> map[i];
    }
    dp[0][0] = 3;
    while (true) {
        auto **dp_next = new int *[m];
        bool change = false;
        for (int i = 0; i < m; ++i) {
            dp_next[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                if (map[i][j] == 'W') {
                    continue;
                }
                auto east = value_at(j + 1, i),
                        south = value_at(j, i + 1),
                        west = value_at(j - 1, i),
                        north = value_at(j, i - 1);
                auto max_surrounding = max(max(east, south), max(west, north));
                auto next = map[i][j] == 'X' ? max_surrounding - 1 : max_surrounding;
                if (next > dp[i][j]) {
                    dp_next[i][j] = next;
                    change = true;
                } else {
                    dp_next[i][j] = dp[i][j];
                }
            }
        }

        delete[] dp;
        dp = dp_next;
        if (!change || dp[m - 1][n - 1] > 0) {
            auto reachable = dp[m - 1][n - 1] > 0;
            delete[] dp;
            return reachable;
        }
    }
}

int main() {
    int k, m, n;
    cin >> k;
    cin >> m >> n;
    for (int i = 0; i < k; ++i) {
        if (has_solution(m, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}